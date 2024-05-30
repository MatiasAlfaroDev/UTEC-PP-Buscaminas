#include <iostream>
#include <time.h>
#include <vector>

#define EMPTY_CELL 0
#define BOMB -1
#define FLAG -2
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

// Function to get color code for a number
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

// Dynamic Board Generation (By Difficulty)
std::vector<std::vector<int>> dynamicBoard(int ROWSIZE, int COLSIZE) {

    std::vector<std::vector<int>> board(ROWSIZE + 1, std::vector<int>(COLSIZE + 1, EMPTY_CELL));
    return board;
}

// Dynamic bomb generation. Number of Bombs / Empty Board (dynamicBoard)
void randBombGen(int bombNum, std::vector<std::vector<int>>& board) {

    int bombCount = 0; // Bomb COUNT limiter.
    int rowCount = board.size(), colCount = board[0].size();

    while (bombCount < bombNum) {
        int row = rand() % rowCount, col = rand() % colCount; // Takes a Random row/col coordinate
        if (board[row][col] != BOMB) {
            board[row][col] = BOMB;
            bombCount++;
        }
    }
}

// Number of bombs in adjacent cells of user selected coordinates.
int bombNearNum(int x, int y, const std::vector<std::vector<int>>& board) {

    int bombNear = 0; // Initialize bombNear
        
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) { // NEEDS UPDATING.
            if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == BOMB) {
                bombNear++;
            }
        }
    }

    return bombNear; // Return the count of nearby bombs
}

bool exploreBoard(int x, int y, std::vector<std::vector<int>>& board) {
    // Check if the current cell is out of bounds or already revealed
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == REVEALED || board[x][y] == FLAG) 
        return false;

    // If the current cell is a bomb, return true indicating game over
    if (board[x][y] == BOMB) 
        return true;

    // Calculate the number of adjacent bombs
    int adjacentBombs = bombNearNum(x, y, board);

    // If there are adjacent bombs, reveal the current cell and return
    if (adjacentBombs > 0) {
        board[x][y] = adjacentBombs;
        return false;
    }

    // If there are no adjacent bombs, reveal the current cell and recursively explore adjacent cells
    board[x][y] = REVEALED;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i != x || j != y) { // Avoid infinite loop by not revisiting the same cell
                exploreBoard(i, j, board);
            }
        }
    }
    return false;
}


// Console print the board by values (EMPTY_CELL, BOMB, FLAG, REVEALED)
void boardPrint(const std::vector<std::vector<int>>& board, bool revealBombs = false) {
    
        for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {

            if (revealBombs && board[i][j] == BOMB) {
                std::cout << MAGENTA << "* " << WHITE;

            } else if (board[i][j] == EMPTY_CELL || board[i][j] == BOMB) {
                std::cout << "- ";

            } else if (board[i][j] == REVEALED) {
                std::cout << GREY <<  ". " << WHITE;

            } else if (board[i][j] == FLAG) {
                std::cout << "⚑ ";

            } else {
                std::cout << getColor(board[i][j]) << board[i][j] << WHITE << " "; // Display number of bombs in adjacent cells with color
            }
        }
        std::cout << std::endl;
    }
}