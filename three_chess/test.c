#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	char ret = 0;
	char arr[ROWS][COLS] = { 0 };
	InitBoard(arr, ROWS, COLS);
	//DisplayBoard(arr, ROWS, COLS);    //��ӡ����
	while (1)
	{
		ComputerMove(arr, ROWS, COLS);      //������
		DisplayBoard(arr, ROWS, COLS);
		ret = CheckWin(arr, ROWS, COLS);
		if (ret != ' ')
		{
			break;
		}
		PlayerMove(arr, ROWS, COLS);        //�����
		DisplayBoard(arr, ROWS, COLS);
	    ret = CheckWin(arr, ROWS, COLS);
		if (ret != ' ')
		{
			break;
		}
	} 
	if (ret == 'X')
	{
		printf("����Ӯ��\n");
	}
	else if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == 'q')
	{
		printf("ƽ�֣�\n");
	}
}
void menu()
{
	printf("****************************************\n");
	printf("********** ��ӭ������������Ϸ **********\n");
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
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
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