#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h> 
#include <windows.h>
#include <assert.h>

char * my_strchr(const char * str, int ch)
{
	assert(str);
	while (*str && (*str != (char)ch))     //�ж϶�Ӧ�ַ��Ƿ��������ַ�
	{
		str++;
	}
	if (*str == (char)ch)
	{
		return (char *)str;      //���ҵ����򷵻����ĵ�ַ
	}
	return NULL;
}

int main()
{
	char str[] = "This is a sample string";
	char *p = my_strchr(str, 's');
	if (p != NULL)
	{
		printf("find the char at : %d\n", p - str + 1);    //�ҵ�Ŀ���ַ����ֵ�λ��
	}
	else
	{
		printf("could not find the char\n");
	}
	system("pause");
	return 0;
}