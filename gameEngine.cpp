#include <iostream>
#include <cstdio>
#include <time.h>

// Using define just for the looks
#define EMPTY_CELL 0
#define BOMB 1
#define FLAG 'M'
#define REVEALED 9

void emptyBoardGen(int board[8][8]) {
    
    for (int i = 0; i < 8; i++) // 8 x 8 Matrix Gen
        for (int j = 0; j < 8; j++) 
            board[i][j] = EMPTY_CELL;
}    

void randBombGen(int bombNum, int board[8][8]) {
    
    int bombCount; // Bomb COUNT limiter.
    srand(time(0));

    while (bombCount < bombNum) {

        int row = rand() % 8, col = rand() % 8; 

            if (board[row][col] != BOMB) board[row][col] = BOMB; bombCount++;   
    }
}

void bombNearNum(int x, int y, int board[8][8]) {

    int bombNear;
        
    for (int i = (x-1); i <= (x+1); i++)
        for (int j = (y-1); j <= (y+1); j++) 
            if (board[i][j] == BOMB) bombNear++;

    board[x][y] = bombNear;
}

void exploreBoard(int x, int y, int board[8][8]) {
     
    if (x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] == REVEALED || board[x][y] == FLAG) return;

    board[x][y] = REVEALED;

}

bool gameOver(int board[8][8]) {

    for (int i = 0; i < 8; ++i) 
        for (int j = 0; j < 8; ++j) 
            if (board[i][j] == BOMB);
    
    return true;
}

void boardPrint(int board[8][8]) {
  
    srand(time(0));
    
    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 8; j++) {
            
            std::cout << board[i][j] << ' ';
        }

        std::cout << std::endl;
    } 
}

