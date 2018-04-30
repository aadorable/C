#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>             //使用当前时钟做种子
void menu()
{
	printf("                                      \n");
	printf("**************************************\n");
	printf("**********1.play******0.exit**********\n");
	printf("**************************************\n");
}
void game()
{
	int num = 0;
	int n = 0;
	num = rand() % 100 + 1;             //产生从1—100之间的随机数，rand函数作用是产生伪随机数
	while (1)
	{
		printf("请输入猜的数字：");
		scanf("%d", &n);
		if (n > num)
		{
			printf("猜大了!\n");
		}
		else if (n < num)
		{
			printf("猜小了!\n");
		}
		else 
		{
			printf("恭喜你，猜对了!\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));        //设置随机数种子，srand函数是随机数发生器的初始化函数
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			break;
		default:
			printf("选择错误，请重新输入！\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}