#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	int num = 0;
	for (i = 0; i < 32; i++)
	{
		if ((value >> i) & 1)           //�ж����ֵĵ�i+1��bitλ�Ƿ�Ϊ1
		{
			num ^= (1 << (31 - i)); //��������num |= (1 << (31 - i));   �����1�ͽ�������31-iλ    
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