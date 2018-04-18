#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <assert.h>

char* my_strncat(char* dest, const char* src,int num)
{
	char *ret = dest;
	assert(dest);
	assert(src);
	while (*dest)
	{
		dest++;
	}
	while (num && (*dest++ = *src++))       //拷贝num长的字符串到目标字符串中
	{
		num--;
	}
	*dest++ = '\0';      //将最后的'\0'拷入字符串中
	return ret;
}
char* my_strncpy(char* dest, const char* src,int num)
{
	char *ret = dest;
	assert(dest);
	assert(src);
	while (num && (*dest++ = *src++))       //拷贝num长的字符串到目标字符串中
	{
		num--;
	} 
	if (num > 0)
	{
		while (--num)
		{
			*dest++ = '\0';     //若num比源字符串长，那么多出的要拷贝字符用'\0'代替
		}
	}
	return ret;
}
int main()
{
	char arr[20] = { 0 };
	char *p = arr;
	my_strncpy(p, "Hellol",5);
	printf("%s\n", p);
	my_strncat(p, " world!!",7);
	printf("%s\n", p);
	system("pause");
	return 0;
}
