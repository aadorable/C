#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Option
{
	EXIT,
	PLAY
};
#define ROW 10
#define COL 10
#define ROWS ROW + 2
#define COLS COL + 2
#define EASY_COUNT 10

void InitBoard(char board[ROWS][COLS], int row, int col, int set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col, int count);
void GetMineCount(char board[ROWS][COLS], char show[ROWS][COLS], int x, int y);

#endif //__GAME_H__