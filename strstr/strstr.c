#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <assert.h>

char *my_strstr(const char *dest, const char *src) 
{
	assert(dest);
	assert(src);
	char *start = (char *)dest;
	char *substart = (char *)src;
	char *ret = (char *)dest;    //保存dest首地址
	while (*ret)
	{
		start = ret;
		while (*start && *substart && (*start == *substart))
		{
			start++;
			substart++;
		}
		if (*substart == '\0')
		{
			return ret;
		}
		substart = (char *)src;
		ret++;         //得到原起始位置的下一个位置
	}
	return NULL;
}
int main()
{
	char str[20] = "abcdefghijk";
	char *p = str;
	printf("%s\n",my_strstr(p, "defg"));
	system("pause");
	return 0;
}

