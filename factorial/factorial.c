#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <assert.h>

//µÝ¹é
int factorial1(int n)
{
	assert(n > 0);
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n*factorial1(n - 1);
	}
}
//·ÇµÝ¹é
int factorial2(int n)
{
	assert(n > 0);
	int sum = 1;
	while (n > 1)
	{
		sum *= n;
		n--;
	}
	return sum;
}
int main()
{
	int num = 0;
	printf("please input a number:");
	scanf("%d", &num);
	printf("%d\n", factorial1(num));
	printf("%d\n", factorial2(num));
	system("pause");
	return 0;
}