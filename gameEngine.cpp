#include <iostream>
#include <time.h>
#include <vector> /* REASONS OF USING:

+ AUTOMATIC RESIZE Without the need of pointers, no hardcoded size.
+ board.size() makes everything dynamic, allowing custom settings. 
+ Implementations have been taught thinking about future enhancements */

#define EMPTY_CELL 0

#define BOMB -1 // Use of negative numbers were implemented in order to prevent mix ups.
#define FLAG -2
#define TRUEFLAG -3 // A FLAG is true when its above a BOMB.
#define REVEALED -8

// ANSI color codes 
#define BLUE "\033[36m"
#define DARK_BLUE "\033[34m"
#define GREEN "\033[32m"
#define RED "\033[91m"
#define DARK_RED "\033[31m"
#define MAGENTA  "\033[95m"
#define CYAN  "\033[36m"
#define VIOLET "\033[35m"
#define WHITE  "\033[37m"
#define GREY "\033[90m"

int moves, flags; // Global moves & flags counters

// Function to get color code for a number (Loyal to OG MineSweeper). 
std::string getColor(int num) {

    switch (num) {

        case 1: return BLUE;
        case 2: return GREEN;
        case 3: return RED;
        case 4: return DARK_BLUE;
        case 5: return DARK_RED;
        case 6: return CYAN;
        case 7: return MAGENTA;
        case 8: return GREY;
        default: return WHITE;
    }
}

// Dynamic Board Generation (By Difficulty).
std::vector<std::vector<int>> dynamicBoard(int ROWSIZE, int COLSIZE) {

    // Create VECTOR by ROWSIZE & COLSIZE.
    std::vector<std::vector<int>> board(ROWSIZE, std::vector<int>(COLSIZE, EMPTY_CELL));
    return board;
}

// Dynamic bomb generation. Number of Bombs / Empty Board (dynamicBoard).
void randBombGen(int bombNum, std::vector<std::vector<int>>& board) {

    int bombCount = 0; // Bomb COUNT limiter.
    int rowCount = board.size(), colCount = board[0].size();

    while (bombCount < bombNum) {

        int row = rand() % rowCount, col = rand() % colCount; // Takes a Random row/col coordinate.

        if (board[row][col] != BOMB) {

                board[row][col] = BOMB;
                bombCount++;
            }
    }
}

// Number of bombs in adjacent cells of user selected coordinates.
int bombNearNum(int x, int y, const std::vector<std::vector<int>>& board) {

    int bombNear = 0; // Initialize bombNear.

    // FOR loop that iterates through the board.
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) { 

            if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == BOMB) {
                bombNear++;
            }
        }
    }

    return bombNear; // Return the count of nearby bombs.
}

// BOOL -> FALSE: Recursive Function | TRUE: Bomb has been hit.
bool exploreBoard(int x, int y, std::vector<std::vector<int>>& board) {
   
    // Check if the current cell is out of bounds or already revealed.
    if (x < 0 || x >= board.size()|| 
        y < 0 || y >= board[0].size()|| 
        board[x][y] == REVEALED ||
        board[x][y] == FLAG || 
        board[x][y] == TRUEFLAG ) 
            return false;

    // If the current cell is a BOMB, return TRUE indicating game over.
    if (board[x][y] == BOMB) 
        return true;

    // Calculate the number of adjacent BOMB.
    int adjacentBombs = bombNearNum(x, y, board);
    if (adjacentBombs > 0) { // If there are adjacent BOMB, reveal the current cell and return.
        board[x][y] = adjacentBombs;
        return false;
    }

    // If there are no adjacent BOMB, reveal the current cell and recursively explore adjacent cells.
    board[x][y] = REVEALED;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i != x || j != y) { // Avoid infinite loop by not revisiting the same cell.
                exploreBoard(i, j, board);
            }
        }
    }

    return false;
}

// Console print the board by values (EMPTY_CELL, BOMB, FLAG, REVEALED)
void boardPrint(const std::vector<std::vector<int>>& board, bool revealBombs = false) {
    
        // FOR loop that iterates through the board.
        for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {

            if (revealBombs && board[i][j] == BOMB) { std::cout << MAGENTA << "* " << WHITE; 

            } else if (board[i][j] == EMPTY_CELL || board[i][j] == BOMB) { std::cout << "- ";

            } else if (board[i][j] == REVEALED) { std::cout << GREY <<  ". " << WHITE;

            } else if ((board[i][j] == FLAG) || (board[i][j] == TRUEFLAG)) { std::cout << "⚑ ";

            } else { std::cout << getColor(board[i][j]) << board[i][j] << WHITE << " "; } // Display number of bombs in adjacent cells with color
        }

        std::cout << std::endl;
    }
}

// Game Win indicator
bool gameWin(const std::vector<std::vector<int>>& board) {

    int boardSize = board.size() * board[0].size(); // Total ammount of cells.
    int revealedCells = 0, flaggedCells = 0;

    // FOR loop that iterates through the board.
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {

            // Counts REVEALED.
            if (board[i][j] == REVEALED) revealedCells++;

            // Counts BOMB
            if (board[i][j] >= 0 && board[i][j] <= 8) revealedCells++;

            // Counts TRUEFLAG.E
            if (board[i][j] == TRUEFLAG) flaggedCells++;

            // Check incorrectly flagged cells (FLAG)
            if (board[i][j] == FLAG && board[i][j] != BOMB) return false; 
        }
    }

    // WIN: TRUE -> All REVEALED & All TRUEFLAG 
    return revealedCells + flaggedCells == boardSize;
}
