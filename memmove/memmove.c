#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <string.h>

void *my_memmove(void *dest,const void *src, int size)
{
	assert(dest);
	assert(src);
	//�������󿽱�
	char *p = (char *)dest;
	char *q = (char *)src;
	if ((char *)dest > (char *)src && (char *)dest < (char *)src + size)
	{
		p = p + size - 1;      //ָ��ָ�����һ��Ԫ��
		q = q + size - 1;
		while (size--)
		{
			*p-- = *q--;
		}
	}
	//�������ҿ���
	else
	{
		while (size--)
		{
			*p++ = *q++;
		}
	}
	return dest;
}
int main()
{
	char arr[20] = "abcdefg";
	my_memmove(arr + 1, arr, strlen(arr) + 1);
	printf("after arr = %s\n", arr);
	system("pause");
	return 0;
}