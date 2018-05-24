#include <stdio.h>
#include <assert.h>

int my_strcmp(const char *str1, const char *str2)
{
	assert(str1);
	assert(str2);
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 == *str2)
		{
			str1++, str2++;
		}
		else if (*str1 > *str2)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	if (*str1 != '\0')
	{
		return 1;
	}
	else if (*str2 != '\0')
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	char str1[] = "abcdeg";
	char str2[] = "abcdef";
	int ret = my_strcmp(str1, str2);
	if (ret > 0)
	{
		printf("%s is greater than %s\n", str1, str2);
	}
	else if (ret == 0)
	{
		printf("%s is the same as %s\n", str1, str2);
	}
	else
	{
		printf("%s is less than %s\n", str1, str2);
	}
	return 0;
}
