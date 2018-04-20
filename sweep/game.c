#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int row, int col, int set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = set;
	}
}
//打印扫完雷之后显示的界面
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	//int j = 0;
	//printf("   ");
	//for (i = 1; i <= col; i++)
	//{
	//	printf("%d ", i);
	//}
	//printf("\n");
	//for (i = 1; i <= row; i++)
	//{
	//	printf("%2d ", i);
	//	for (j = 1; j <= col; j++)
	//	{
	//		printf("%c ", board[i][j]);
	//	}
	//	printf("\n");
	//}
	//printf("\n");
	printf("     1   2   3   4   5   6   7   8   9   10\n");
	printf("   |---|---|---|---|---|---|---|---|---|---|\n");
	for (i = 1; i <= row; i++)
	{
		printf("%2d ", i);
		printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", board[i][1], board[i][2], board[i][3], board[i][4], 
			board[i][5], board[i][6], board[i][7], board[i][8], board[i][9], board[i][10]);
		printf("   |---|---|---|---|---|---|---|---|---|---|\n");
	}
	printf("\n");
}
//设置雷的位置
void SetMine(char board[ROWS][COLS], int row, int col, int count)
{
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
//遍历周围雷的数量
void GetMineCount(char board[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (board[x][y] == '0')
	{
		int count = 0;
		if (board[x - 1][y] == '1')
			count++;
		if (board[x - 1][y - 1] == '1')
			count++;
		if (board[x][y - 1] == '1')
			count++;
		if (board[x + 1][y - 1] == '1')
			count++;
		if (board[x + 1][y] == '1')
			count++;
		if (board[x + 1][y + 1] == '1')
			count++;
		if (board[x][y + 1] == '1')
			count++;
		if (board[x - 1][y + 1] == '1')
			count++;
		show[x][y] = (count + '0');      //确定是字符数字
	}
	if (show[x][y] == '0')
	{
		if (show[x - 1][y] == '*')
			GetMineCount(board, show, x - 1, y);
		if (show[x - 1][y - 1] == '*')
			GetMineCount(board, show, x - 1, y - 1);
		if (show[x][y - 1] == '*')
			GetMineCount(board, show, x, y - 1);
		if (show[x + 1][y - 1] == '*')
			GetMineCount(board, show, x + 1, y - 1);
		if (show[x + 1][y] == '*')
			GetMineCount(board, show, x + 1, y);
		if (show[x + 1][y + 1] == '*')
			GetMineCount(board, show, x + 1, y + 1);
		if (show[x][y + 1] == '*')
			GetMineCount(board, show, x, y + 1);
		if (show[x - 1][y + 1] == '*')
			GetMineCount(board, show, x - 1, y + 1);
	}
}

