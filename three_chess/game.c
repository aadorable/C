#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void DisplayBoard(char board[ROWS][COLS], int rows, int cols)    
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		printf(" %c | %c | %c \n", board[i][0],board[i][1],board[i][2]);
		if (i != rows-1)
			printf("---|---|---\n");
	}
	printf("\n");
}
void InitBoard(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void ComputerMove(char board[ROWS][COLS], int rows, int cols)
{
	int x = 0;
	int y = 0;
	printf("电脑走：>\n");
	while (1)
	{
		x = rand() % rows;
		y = rand() % cols;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'X';
			break;
		}
	}
}
void PlayerMove(char board[ROWS][COLS], int rows, int cols)
{
	int x = 0;
	int y = 0;
	printf("玩家走：>\n");
	while (1)
	{
		printf("请输入坐标：(x y)>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= rows && y >= 1 && y <= cols)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该位置已被占用！\n");
			}
		}
		else
		{
			printf("此坐标为非法坐标，请重新输入！\n");
		}
	}
}
static int IsFull(char board[ROWS][COLS], int rows, int cols)     //只在这一个函数中使用
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char CheckWin(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	for (i = 0; i < cols; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (IsFull(board, rows, cols))
	{
		return 'q';           //代表平局
	}
	return ' ';
}
