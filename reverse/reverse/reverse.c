#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	int num = 0;
	for (i = 0; i < 32; i++)
	{
		if ((value >> i) & 1)           //判断数字的第i+1个bit位是否为1
		{
			num ^= (1 << (31 - i)); //方法二：num |= (1 << (31 - i));   如果是1就将其左移31-i位    
		}
	}
	return num;
}
int main()
{
	int num = 0;
	printf("please input a number:");
	scanf("%d", &num);
	printf("reverse_bit is %u\n", reverse_bit(num));
	system("pause");
	return 0;
}