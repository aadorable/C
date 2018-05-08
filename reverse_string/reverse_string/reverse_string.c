#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <assert.h>

void reverse_string(char *str)
{
	assert(str);
	if (*str == '\0')
	{
		return;
	}
	else
	{
		reverse_string(str + 1);
	}
	printf("%c ", *str);
}
int main()
{
	char str[] = "abcdefg";
	reverse_string(str);
	printf("\n");
	system("pause");
	return 0;
}