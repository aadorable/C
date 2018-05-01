#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <string.h>

void bubble_sort_str(char(*p)[10], int row)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row - 1 - i; j++)
		{
			if (strcmp(p[j], p[j + 1]) > 0)
			{
				char tmp[10] = { 0 };
				strcpy(tmp, p[j]);
				strcpy(p[j],p[j+1]);
				strcpy(p[j+1], tmp);
			}
		}
	}
}
int main()
{
	char str[5][10] = { "Aoei", "adcbef", "dw", "wrold", "hello" };
	int len = sizeof(str) / sizeof(*str);
	bubble_sort_str(str,len);
	for (int i = 0; i < len; i++)
	{
		printf("%s\n", str[i]);
	}
	system("pause");
	return 0;
}