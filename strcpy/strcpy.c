#include <stdio.h>
#include <assert.h>

char* my_strcat(char* dest, const char* src)
{
	char *ret = dest;
	assert(dest);
	assert(src);
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
char* my_strcpy(char* dest, const char* src)
{
	char *ret = dest;
	assert(dest);
	assert(src);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr[20] = { 0 };
	char *p = arr;
	my_strcpy(p, "Hello");
	printf("%s\n", p);
	my_strcat(p, " world!");
	printf("%s\n", p);
	return 0;
}
