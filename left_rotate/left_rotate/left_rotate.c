#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

//static void LeftOnce(char str[], int lenght)
//{
//	int tmp = str[0];
//	int i = 0;
//	for (i = 0; i<lenght - 1; i++)
//	{
//		str[i] = str[i + 1];
//	}
//	str[i] = tmp;
//}
//void LeftRotate(char str[], int lenght, int num)
//{
//	assert(str);
//	assert(lenght > 0);
//	assert(num > 0);
//	num %= lenght;      //有效次数
//	while (num)
//	{
//		LeftOnce(str, lenght);
//		num--;
//	}
//}
//static reverse(char *p, char *q)
//{
//	while (p<q)
//	{
//		*p ^= *q;
//		*q ^= *p;
//		*p ^= *q;
//		p++, q--;
//	}
//}
//void LeftRotate(char str[], int lenght, int num)
//{
//	assert(str);
//	assert(lenght > 0);
//	assert(num > 0);
//	num %= lenght;      //有效次数
//	reverse(str, str + num - 1);
//	reverse(str + num, str + lenght - 1);
//	reverse(str, str + lenght - 1);
//}
void LeftRotate(char str1[], int lenght, int num)
{
	assert(str1);
	assert(lenght > 0);
	assert(num > 0);
	num %= lenght;      //有效次数
	int size = 2 * lenght + 1;
	char *p = (char*)malloc(sizeof(char)*size);
	strcpy(p, str1);
	strcat(p, str1);     //将两字符串拼接
	strncpy(str1, p + num, lenght);
	free(p);
}
static int Check(char str1[], char str2[])
{
	assert(str1);
	assert(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str1);
	if (len1 != len2)
	{
		return -1;
	}
	else if (strcmp(str1, str2) == 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int num = 0;
	printf("please input a number:");
	scanf("%d", &num);
	char str1[] = "abcdefg";
	char str2[] = "cdefgab";
	printf("before:%s\n", str1);
	LeftRotate(str1, strlen(str1), num);
	printf("after:%s\n", str1);
	int ret = Check(str1, str2);
	if (ret == 1)
	{
		printf("same!\n");
	}
	else
	{
		printf("different!\n");
	}
	system("pause");
	return 0;
}