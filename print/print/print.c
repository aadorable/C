#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <assert.h>

void reverse(char* p, char* q)
{
	while (p < q)
	{
		*p ^= *q;
		*q ^= *p;
		*p ^= *q;
		p++,q--;
	}
}
void str_reverse(char* str)
{
	assert(str);
	char *p = str;           //定义指针变量指向首元素地址
	char *q = p;
	while (*p)               //判断p是否指向空
	{
		if (isspace(*p))     //isspace是标C提供用来判定字符是否为空的函数
		{
			reverse(q, p - 1);    //局部逆置       
			p++;
			q = p;
		}
		else
		{
			p++;
		}
	}
	reverse(q, p - 1);
	reverse(str, p - 1);            //整体逆置
}
int main()
{
	char str[] = "student a am i";
	str_reverse(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}