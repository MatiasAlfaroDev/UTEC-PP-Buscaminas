#include <iostream>
#include <ctime>
#include <vector>

#define EMPTY_CELL 0
#define BOMB -1
#define FLAG -2
#define REVEALED -8

// ANSI color codes
const std::string RESET = "\033[0m";
const std::string BLUE = "\033[34m";
const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string MAGENTA = "\033[35m";
const std::string YELLOW = "\033[33m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string BRIGHT_WHITE = "\033[97m";

// Function to get color code for a number
std::string getColor(int num) {

    switch (num) {

        case 1: return BLUE;
        case 2: return GREEN;
        case 3: return RED;
        case 4: return MAGENTA;
        case 5: return YELLOW;
        case 6: return CYAN;
        case 7: return WHITE;
        case 8: return BRIGHT_WHITE;
        default: return RESET;
    }
}

// Dynamic Board Generation (By Difficulty)
std::vector<std::vector<int>> dynamicBoard(int ROWSIZE, int COLSIZE) {

    std::vector<std::vector<int>> board(ROWSIZE, std::vector<int>(COLSIZE, EMPTY_CELL));
    return board;
}

bool gameOver(const std::vector<std::vector<int>>& board) {

    for (const auto& row : board) {
        for (int cell : row) {
            if (cell == BOMB) {
                return true;
            }
        }
    }
    return false;
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
                std::cout << "* ";

            } else if (board[i][j] == EMPTY_CELL || board[i][j] == BOMB) {
                std::cout << "- ";

            } else if (board[i][j] == REVEALED) {
                std::cout << ". ";

            } else if (board[i][j] == FLAG) {
                std::cout << "⚑ ";

            } else {
                std::cout << getColor(board[i][j]) << board[i][j] << RESET << " "; // Display number of bombs in adjacent cells with color
            }
        }
        std::cout << std::endl;
    }
}