#include <stdio.h>
#include <assert.h>

void reverse_string(char *str)
{
	assert(str);
	if (*str == '\0')
	{
		return;
	}
	else
	{
		reverse_string(str + 1);
	}
	printf("%c ", *str);
}
int main()
{
	char str[] = "abcdefg";
	reverse_string(str);
	printf("\n");
	return 0;
}
