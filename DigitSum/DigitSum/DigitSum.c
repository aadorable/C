#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <assert.h>

int DigitSum(int n)
{
	assert(n > 0);
	if (n <= 9)
	{
		return n;
	}
	else
	{
		return DigitSum(n / 10) + n % 10;
	}
}
int main()
{
	int num = 0;
	printf("please input a number:");
	scanf("%d", &num);
	printf("%d\n", DigitSum(num));
	system("pause");
	return 0;
}
