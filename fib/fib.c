#include <stdio.h>
#include <assert.h>

//µİ¹é
int fib1(int num)
{
	assert(num > 0);
	if (num <= 2)
	{
		return 1;
	}
	else
	{
		return fib1(num - 1) + fib1(num - 2);
	}
}
//·Çµİ¹é
int fib2(int num)
{
	assert(num > 0);
	int f1 = 1;
	int f2 = 1;
	int f3 = 0;
	if (num <= 2)
	{
		return 1;
	}
	else
	{
		while (num-- > 2)
		{
		    f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		return f3;
	}
}
int main()
{
	int num = 0;
	printf("please input a number:");
	scanf("%d", &num);
	printf("%d\n", fib1(num));
	printf("%d\n", fib2(num));
	return 0;
}
