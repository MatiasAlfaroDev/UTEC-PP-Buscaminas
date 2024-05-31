#include "./gameEngine.cpp"
#include "./GUI.cpp"

int main() {
    
    srand(time(0)); // Seed for random number generation.

    int sizeY, sizeX, bombsCount;
    char difficulty, understood;
   
    startingGUI();
        std::cin >> difficulty; // Dynamic Difficulty, you can change up board X & Y size below.

        while (true) {

                if (difficulty == 'A') { sizeY = sizeX = 8, bombsCount = 16; break; } // Beginner.
                    else if  (difficulty == 'B') { sizeY = sizeX = 16, bombsCount = 40; break; } // Intermediate.
                        else if  (difficulty == 'C') { sizeY = 10, sizeX = 45, bombsCount = 50; break; } // Advanced.
                            else { std::cout << MAGENTA  << "  ____________________________________________________" << std::endl << "  -Miney: "<< WHITE <<"Don't be a meanie, select a valid DIFFICULTY: "; 
                                std::cin >> difficulty; }
        };

    system("clear");

        while (true) {

            rules(bombsCount);

            std::cout << MAGENTA  << "  ________________________" << std::endl << "  -Miney: "<< WHITE <<"Understood? [Y/N]: " << WHITE;
            std::cin >> understood;

            if (understood == 'Y') { break; system("clear"); } 
            else { 
                
                system("clear");
                std::cout << MAGENTA  << "  ______________________" << std::endl << "  -Miney: "<< WHITE <<"Read 'em again." << WHITE << std::endl;
            }
        }
    
    system("clear");
    
    // Generate board with sizeY & sizeX defined in "difficulty".
    std::vector<std::vector<int>> gameBoard = dynamicBoard(sizeY, sizeX);
    randBombGen(bombsCount, gameBoard);

    
    // Game loop, exits when FALSE (BOMB Hit).
    while (true) {

        boardPrint(gameBoard);

        // User input.
        int x, y, safeX, safeY;
        char action;

        std::cout << MAGENTA  << std::endl << MAGENTA  << " MOVES: " << WHITE << moves << MAGENTA << "                              FLAGS: " << WHITE << flags << MAGENTA << "/" <<  WHITE << bombsCount << std::endl;
        std::cout << MAGENTA << " _________________________________________________" << std::endl << " -Miney: " << WHITE << "Please, enter COORDINATES |ROW COL ACTION|:";
        
        std::cin >> x >> y >> action;
        system("clear");

        if (gameWin(gameBoard)) {

            boardPrint(gameBoard);
            std::cout << MAGENTA << " _______________________________" << std::endl << " -Miney: " << WHITE << "Congratulations! You win!" << WHITE << std::endl;
            break;

        }

        // Validate user COORDINATES input.
        if (x < 0 || x >= sizeY || y < 0 || y >= sizeX) {

            std::cout << MAGENTA << " ______________________________________" << std::endl << " -Miney: " << WHITE << "Please, enter valid COORDINATES." << WHITE << std::endl << "      " << std::endl;
            std::cout << WHITE << "      " << std::endl;
            continue;
        } 

        // Validate user ACTION input.
        if (action != 'E' && action != 'F') {

            std::cout << MAGENTA  << " __________________________________" << std::endl << "-Miney: "<< WHITE <<"Please enter a valid ACTION." << WHITE << std::endl << "      " << std::endl;
            std::cout << WHITE << "      " << std::endl;
            continue;
        }
        
        // Take action based on user input.
        if (action == 'E') {

            moves++; // For each valid move it increases by one.
            if (gameBoard[x][y] == REVEALED) std::cout << MAGENTA  << " __________________________________________________________" << std::endl << " -Miney: "<< WHITE <<"Invalid input. You can't Explore a discovered cell." << WHITE << std::endl << "      " << std::endl;
            
            if (exploreBoard(x, y, gameBoard) ) { // (if (TRUE) | Triggers when a BOMB is found.
                
                // Print the board with ALL BOMB revealed.
                boardPrint(gameBoard, true);
                std::cout << MAGENTA  << " _________________________________" << std::endl << " -Miney: " << WHITE << "You hit a bomb. GAME OVER.\n" << WHITE << std::endl;
                break;

            } 

        } else if (action == 'F') {

            moves++; // For each valid move it increases by one.
            // Toggle FLAG on the cell.
            switch(gameBoard[x][y]) {
                
                // Cases when a FLAG is/isn't placed.
                case REVEALED : std::cout << MAGENTA  << " _______________________________________________________" << std::endl << " -Miney: "<< WHITE <<"Invalid input. You can't flag a discovered cell." << WHITE << std::endl << "      " << std::endl; continue;
                case FLAG : gameBoard[x][y] = EMPTY_CELL; moves++ ; flags--; continue;
                case TRUEFLAG : gameBoard[x][y] = EMPTY_CELL; moves++ ; flags--; continue;
                case EMPTY_CELL : gameBoard[x][y] = FLAG; moves++; flags++; continue;
                case BOMB : gameBoard[x][y] = TRUEFLAG; moves++; flags++; continue; // FLAG over bombs get a different value. (TRUEFLAG).
                default : std::cerr << RED <<  "[CRITICAL ERROR]" << WHITE << std::endl; continue; // It never should reach this.
            }   
        }

        // Check WIN after TRUEFLAG.
        if (flags == bombsCount) {
            
            bool allBombsFlagged = true;
                // Check BOMB is TRUEFLAG.
                for (int i = 0; i < sizeX; i++) {
                    for (int j = 0; j < sizeY; j++) {
                        
                        if (gameBoard[i][j] == BOMB && gameBoard[i][j] != TRUEFLAG) {
                            allBombsFlagged = false;
                            break;
                        }
                    }
                }
            

            bool allCellsRevealed = true;
                // Check REVEALED.
                for (int i = 0; i < sizeX; i++) {
                    for (int j = 0; j < sizeY; j++) {
                        
                        if (gameBoard[i][j] != REVEALED && gameBoard[i][j] != BOMB) {
                            allCellsRevealed = false;
                            break;
                        }
                    }
                }

            if (allBombsFlagged && allCellsRevealed) {
            
                boardPrint(gameBoard);
                std::cout << MAGENTA << " _______________________________" << std::endl << " -Miney: " << WHITE << "Congratulations! You win!" << WHITE << std::endl;
                return 0; 
            }
        }
    };

    return 0;

}