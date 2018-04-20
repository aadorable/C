#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	char ret = 0;
	char arr[ROWS][COLS] = { 0 };
	InitBoard(arr, ROWS, COLS);
	//DisplayBoard(arr, ROWS, COLS);    //打印棋盘
	while (1)
	{
		ComputerMove(arr, ROWS, COLS);      //电脑走
		DisplayBoard(arr, ROWS, COLS);
		ret = CheckWin(arr, ROWS, COLS);
		if (ret != ' ')
		{
			break;
		}
		PlayerMove(arr, ROWS, COLS);        //玩家走
		DisplayBoard(arr, ROWS, COLS);
	    ret = CheckWin(arr, ROWS, COLS);
		if (ret != ' ')
		{
			break;
		}
	} 
	if (ret == 'X')
	{
		printf("电脑赢！\n");
	}
	else if (ret == '*')
	{
		printf("玩家赢！\n");
	}
	else if (ret == 'q')
	{
		printf("平局！\n");
	}
}
void menu()
{
	printf("****************************************\n");
	printf("********** 欢迎进入三子棋游戏 **********\n");
	printf("***********1.play      0.exit***********\n");
	printf("****************************************\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}