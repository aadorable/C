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
	InitBoard(mine, ROWS, COLS,'0');    //������
	InitBoard(show, ROWS, COLS,'*');    //���׵���Ϣ
	DisplayBoard(show, ROW, COL);
	SetMine(mine, ROW, COL, EASY_COUNT);  //������
	//DisplayBoard(mine, ROW, COL);
	while (win < ROW*COL - EASY_COUNT)
	{
		printf("���������꣺>");
		scanf("%d %d", &x, &y);
		printf("\n");
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)    //�ж���������Ϸ�
		{
			if (mine[x][y] == '1' && n == 1)            //����һ�����ף�����ת��
			{
				mine[x][y] = '0';
				SetMine(mine, ROW, COL, 1);
			}
			n++;
			//DisplayBoard(mine, ROW, COL);
			if (mine[x][y] == '1' && n != 1)
			{
				printf("   �ܲ��Ҳȵ����ˣ��ٽ�������\n");
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
			printf("������Ϊ�Ƿ�����,���������룡\n");
		}
	}
	if (win == ROW*COL -EASY_COUNT)
	{
		printf("   ��ϲ�㣬���׳ɹ���\n");
	}
}
void menu()
{
	printf("****************************************\n");
	printf("*********** ��ӭ����ɨ����Ϸ ***********\n");
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
		printf("��ѡ��ģʽ��>");
		scanf("%d", &input);
		switch (input)
		{
		case PLAY:
			game();
			break;
		case EXIT:
			break;
		default:
			printf("ѡ�����������ѡ��\n");
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