#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	int win = 0;
	int x = 0;
	int y = 0;
	int n = 1;
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS,'0');    //布置雷
	InitBoard(show, ROWS, COLS,'*');    //排雷的信息
	DisplayBoard(show, ROW, COL);
	SetMine(mine, ROW, COL, EASY_COUNT);  //设置雷
	//DisplayBoard(mine, ROW, COL);
	while (win < ROW*COL - EASY_COUNT)
	{
		printf("请输入坐标：>");
		scanf("%d %d", &x, &y);
		printf("\n");
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)    //判断输入坐标合法
		{
			if (mine[x][y] == '1' && n == 1)            //若第一个是雷，将其转移
			{
				mine[x][y] = '0';
				SetMine(mine, ROW, COL, 1);
			}
			n++;
			//DisplayBoard(mine, ROW, COL);
			if (mine[x][y] == '1' && n != 1)
			{
				printf("   很不幸踩到雷了，再接再厉！\n");
				printf("\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else if (mine[x][y] == '0')
			{
				GetMineCount(mine, show, x, y);
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("此坐标为非法坐标,请重新输入！\n");
		}
	}
	if (win == ROW*COL -EASY_COUNT)
	{
		printf("   恭喜你，排雷成功！\n");
	}
}
void menu()
{
	printf("****************************************\n");
	printf("*********** 欢迎进入扫雷游戏 ***********\n");
	printf("************1.play   0.exit*************\n");
	printf("****************************************\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择模式：>");
		scanf("%d", &input);
		switch (input)
		{
		case PLAY:
			game();
			break;
		case EXIT:
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