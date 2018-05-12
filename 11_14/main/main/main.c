#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <string.h>

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x*y;
}
int Div(int x,int y)
{
	if (y == 0)
	{
		return 0;
	}
	else
	{
		return x / y;
	}
}
int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("输入参数太少！\n");
		system("pause");
		return 0;
	}
	int num1 = atoi(argv[2]);
	int num2 = atoi(argv[3]);
	if (strcmp(argv[1],"-a") == 0)
	{
		int ret = Add(num1, num2);
		printf("ret = %d\n", ret);
	}
	else if (strcmp(argv[1], "-s") == 0)
	{
		int ret = Sub(num1, num2);
		printf("ret = %d\n", ret);
	}
	else if (strcmp(argv[1], "-m") == 0)
	{
		int ret = Mul(num1, num2);
		printf("ret = %d\n", ret);
	}
	else if (strcmp(argv[1], "-d") == 0)
	{
		int ret = Div(num1, num2);
		if (ret == 0)
		{
			printf("除数不能为0\n");
		}
		else
		{
			printf("ret = %d\n", ret);
		}
	}
	else
	{
		printf("输入参数错误！\n");
	}
	system("pause");
	return 0;
}