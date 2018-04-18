#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h> 
#include <windows.h>
#include <assert.h>

char * my_strchr(const char * str, int ch)
{
	assert(str);
	while (*str && (*str != (char)ch))     //判断对应字符是否是所找字符
	{
		str++;
	}
	if (*str == (char)ch)
	{
		return (char *)str;      //若找到了则返回它的地址
	}
	return NULL;
}

int main()
{
	char str[] = "This is a sample string";
	char *p = my_strchr(str, 's');
	if (p != NULL)
	{
		printf("find the char at : %d\n", p - str + 1);    //找到目标字符出现的位置
	}
	else
	{
		printf("could not find the char\n");
	}
	system("pause");
	return 0;
}