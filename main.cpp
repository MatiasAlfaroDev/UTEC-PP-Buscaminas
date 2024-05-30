#include "./gameEngine.cpp"
#include "./GUI.cpp"

int main() {
    
    srand(time(0)); // Seed for random number generation

    int boardSizeX, boardSizeY, bombsCount;
    char difficulty;
   
    startingGUI();
        std::cin >> difficulty; // Dynamic Difficulty, you can change up board X & Y size below

        while (true) {

                if (difficulty == 'A') { boardSizeX = boardSizeY = 8, bombsCount = 16; break; }
                    else if  (difficulty == 'B') { boardSizeX = boardSizeY = 16, bombsCount = 40; break; }
                        else if  (difficulty == 'C') { boardSizeX = 10, boardSizeY = 45, bombsCount = 99; break; }
                            else { std::cout << MAGENTA  << "  ____________________________________________________" << std::endl << "  -Miney: "<< WHITE <<"Don't be a meanie, select a valid DIFFICULTY: "; 
                                std::cin >> difficulty; }
        };

    system("clear");

    char understood;
        while (true) {

            rules(bombsCount);
            std::cout << MAGENTA  << "  ________________________" << std::endl << "  -Miney: "<< WHITE <<"Understood? [Y/N]: " << WHITE;
            std::cin >> understood;

            if (understood == 'Y') {break; system("clear");}
            else {

                system("clear");
                std::cout << MAGENTA  << "  ______________________" << std::endl << "  -Miney: "<< WHITE <<"Read 'em again." << WHITE << std::endl;
            }
        }
    
    system("clear");
    
    std::vector<std::vector<int>> gameBoard = dynamicBoard(boardSizeX, boardSizeY);
    randBombGen(bombsCount, gameBoard);

    
    // Game loop, returns false if a bomb gets hit.
    while (true) {

        boardPrint(gameBoard);

        // User input.
        int x, y, moves, flags;
        char action;

        std::cout << MAGENTA  << std::endl << MAGENTA  << " MOVES: " << WHITE << moves << MAGENTA << "                              FLAGS: " << WHITE << flags << MAGENTA << "/" <<  WHITE << bombsCount << std::endl;
        std::cout << MAGENTA << " _________________________________________________" << std::endl << " -Miney: " << WHITE << "Please, enter COORDINATES |ROW COL ACTION|:";
        
        std::cin >> x >> y >> action;
        system("clear");

        // Validate user COORDINATES input.
        if (x < 0 || x >= boardSizeX || y < 0 || y >= boardSizeY) {

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
        
        // Take action based on user input
        if (action == 'E') {

            if (gameBoard[x][y] == REVEALED) std::cout << MAGENTA  << " __________________________________________________________" << std::endl << " -Miney: "<< WHITE <<"Invalid input. You can't Explore a discovered cell." << WHITE << std::endl << "      " << std::endl;
            moves++;

            if (exploreBoard(x, y, gameBoard) ) { // (if (TRUE)) Triggers when a bombs is found.
                
                // Print the board with bombs revealed.
                boardPrint(gameBoard, true);
                std::cout << MAGENTA  << " _________________________________" << std::endl << " -Miney: " << WHITE << "You hit a bomb. GAME OVER.\n" << WHITE << std::endl;
                break;

            } 

        } else if (action == 'F') {

            // Toggle flag on the cell
            switch(gameBoard[x][y]) {

                case REVEALED : std::cout << MAGENTA  << " _______________________________________________________" << std::endl << " -Miney: "<< WHITE <<"Invalid input. You can't flag a discovered cell." << WHITE << std::endl << "      " << std::endl; continue;
                case FLAG : gameBoard[x][y] = EMPTY_CELL; moves++ ; flags--; continue;
                case EMPTY_CELL : gameBoard[x][y] = FLAG; moves++; flags++; continue;
                case BOMB : gameBoard[x][y] = FLAG; moves++; flags++; continue;
                default : std::cerr << RED <<  "[CRITICAL ERROR] Unknow State. Check Code!\n" << WHITE; continue; // It never should reach this.
            }   
        }
    };

return 0;

}
