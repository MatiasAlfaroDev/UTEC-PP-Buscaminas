#include "./gameEngine.cpp"
#include "./GUI.cpp"

int main() {
    
    srand(time(0)); // Seed for random number generation

    int boardSizeX, boardSizeY, bombsCount;
    char difficulty;
    
   
    startingGUI();
        std::cin >> difficulty;

        while (true) {

                if (difficulty == 'A') { boardSizeX = boardSizeY = 8, bombsCount = 16; break; }
                    else if  (difficulty == 'B') { boardSizeX = boardSizeY = 16, bombsCount = 40; break; }
                        else if  (difficulty == 'C') { boardSizeX = 16, boardSizeY = 30, bombsCount = 99; break; }
                            else { std::cout << CYAN  << "  ___________________________________________________________" << std::endl << "  -Miney: "<< WHITE <<"Don't be a meanie, select a valid DIFFICULTY: "; 
                                std::cin >> difficulty; }
        };
    
    std::vector<std::vector<int>> gameBoard = dynamicBoard(boardSizeX, boardSizeY);
    randBombGen(bombsCount, gameBoard);

    // Game loop, returns false if a bomb gets hit.
    while (true) {

        boardPrint(gameBoard);// Print the board

        // User input.
        int x, y;
        char action;

        std::cout << "Enter Row [0 - " << boardSizeX << "] & Column [0 - " << boardSizeY << "] & ACTION [E: Explore | F: Flag]: ";
        std::cin >> x >> y >> action;

        // Validate user COORDINATES input.
        if (x < 0 || x >= boardSizeX || y < 0 || y >= boardSizeY) {

            std::cout << CYAN  << " ___________________________________________________________" << std::endl << "-Miney: "<< WHITE <<"Please, enter valid COORDINATES." << WHITE << std::endl;
            continue;
        } 

        // Validate user ACTION input.
        if (action != 'E' && action != 'F') {

        std::cout << CYAN  << " ___________________________________________________________" << std::endl << "-Miney: "<< WHITE <<"Please enter a valid ACTION." << WHITE << std::endl;
            continue;
        }
        
        // Take action based on user input
        if (action == 'E') {

            if (exploreBoard(x, y, gameBoard)) { // (if (TRUE)) Triggers when a bombs is found.

                // Print the board with bombs revealed.
                boardPrint(gameBoard, true);
                std::cout << CYAN  << " ___________________________________________________________" << std::endl << " -Miney: "<< "You hit a bomb at [" << x << " - " << y << "] GAME OVER.\n" << WHITE << std::endl;
                break;

            } else if (gameBoard[x][y] == REVEALED) std::cout << CYAN  << " ___________________________________________________________" << std::endl << " -Miney: "<< WHITE <<"Invalid input. You can't Explore a discovered cell." << WHITE << std::endl;

        } else if (action == 'F') {

            // Toggle flag on the cell
            switch(gameBoard[x][y]) {

                case REVEALED :  std::cout << CYAN  << " ___________________________________________________________" << std::endl << " -Miney: "<< WHITE <<"Invalid input. You can't flag a discovered cell." << WHITE << std::endl; continue;
                case FLAG : gameBoard[x][y] = EMPTY_CELL; continue;
                case EMPTY_CELL : gameBoard[x][y] = FLAG; continue;
                default : std::cerr << RED <<  "Unknow State.\n" << WHITE; continue; // It never should reach this.
            }   
        }
    };

return 0;

}