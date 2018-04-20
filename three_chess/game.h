#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void DisplayBoard(char board[ROWS][COLS],int rows,int cols);
void InitBoard(char board[ROWS][COLS], int rows, int cols);
void ComputerMove(char board[ROWS][COLS], int rows, int cols);
void PlayerMove(char board[ROWS][COLS], int rows, int cols);
char CheckWin(char board[ROWS][COLS], int rows, int cols);

#endif //__GAME_H__