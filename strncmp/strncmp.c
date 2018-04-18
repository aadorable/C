#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <assert.h>

int my_srtncmp(const char *str1, const char *str2, size_t num)
{
	assert(str1);
	assert(str2);
	while (num && (*str1 == *str2))      //比较str1和str2中前num个字符的大小
	{
		str1++;
		str2++;
		num--;
	}
	if (num > 0)
	{
		return *str1 - *str2;       //将所有字符比较完后证明两字符串相等
	}
	else
	{
		return *(str1 - 1) - *(str2 - 1);     //当遇到不相等时，指向的是不相等的字符
	}
}
int main()
{
	char str[][5] = { "rode", "ride", "root" };
	int i = 0;
	for (; i < 3; i++)
	{
		if (my_srtncmp(str[i], "rore", 2) == 0)
		{
			printf("result [%d] :%s\n", i, str[i]);
		}
	}
	system("pause");
	return 0;
}