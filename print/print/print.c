#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <assert.h>

void reverse(char* p, char* q)
{
	while (p < q)
	{
		*p ^= *q;
		*q ^= *p;
		*p ^= *q;
		p++,q--;
	}
}
void str_reverse(char* str)
{
	assert(str);
	char *p = str;           //����ָ�����ָ����Ԫ�ص�ַ
	char *q = p;
	while (*p)               //�ж�p�Ƿ�ָ���
	{
		if (isspace(*p))     //isspace�Ǳ�C�ṩ�����ж��ַ��Ƿ�Ϊ�յĺ���
		{
			reverse(q, p - 1);    //�ֲ�����       
			p++;
			q = p;
		}
		else
		{
			p++;
		}
	}
	reverse(q, p - 1);
	reverse(str, p - 1);            //��������
}
int main()
{
	char str[] = "student a am i";
	str_reverse(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}