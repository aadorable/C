#include <stdio.h>
#include <assert.h>

void *my_memcpy(void *dest,const void *src, int count)
{
	assert(dest);
	assert(src);
	assert(count > 0);
	char *p = (char *)dest;
	char *q = (char *)src;
	while (count--)
	{
		*p++ = *q++;
	}
	return dest;
}
int main()
{
	char arr[] = "abcdefg";
	char buff[10];
	my_memcpy(buff,arr,sizeof(arr));
	printf("buff = %s\n", buff);
	return 0;
}
