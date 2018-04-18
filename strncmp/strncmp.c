#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <assert.h>

int my_srtncmp(const char *str1, const char *str2, size_t num)
{
	assert(str1);
	assert(str2);
	while (num && (*str1 == *str2))      //�Ƚ�str1��str2��ǰnum���ַ��Ĵ�С
	{
		str1++;
		str2++;
		num--;
	}
	if (num > 0)
	{
		return *str1 - *str2;       //�������ַ��Ƚ����֤�����ַ������
	}
	else
	{
		return *(str1 - 1) - *(str2 - 1);     //�����������ʱ��ָ����ǲ���ȵ��ַ�
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