#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<windows.h>

void *c = NULL;
void bug()
{
	int a = 0;
	int *p = &a;
	p += 2;
	*p = (int)c;
	printf("I am a bug!\n");
	system("pause");
}
int Add(int x, int y)
{
	printf("Add......done!\n");
	//printf("before y:%d\n", y);
	int *p = &x;
	p--;
	c = (void*)*p;    //将p中的内容保存
	*p =(int) bug;
	//printf("after y:%d\n", y);
	return 0;
}
int main()
{
	int a = 10;
	int b = 20;
	printf("main.....begin!\n");
	int ret = 0;
	ret = Add(a, b);
	printf("you should run here!\n ret = %d\n", ret);
	_asm
	{
		sub esp,4          //为了平衡栈帧结构
	}
	system("pause");
	return 0;
}