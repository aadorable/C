//模拟实现qsort函数
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int int_cmp(const void *p1, const void *p2)      //回调函数
{
	return (*(int *)p1 > *(int *)p2);          //按从小到大顺序排序
}
int int_cmp1(const void *p1, const void *p2)      //回调函数
{
	return (*(int *)p1 < *(int *)p2);          //按从大到小顺序排序
}
void swap(void *p1, void *p2, int size)
{
	char *x = (char *)p1;
	char *y = (char *)p2;
	while (size--)
	{
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
		x++; 
		y++;
	}
}
void my_qsort(void *base, int count, int size, int(*cmp)(const void *,const void *))
{
	assert(base);
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		int flag = 0;
		for (j = 0; j < count - 1 - i; j++)
		{
			if (cmp((char *)base + j*size, (char *)base + (j + 1)*size) > 0)
			{
				flag = 1;
				swap((char *)base + j*size, (char *)base + (j + 1)*size, size);    //交换
			}
		}
		if (flag == 0)        //若排序一次没有变化直接结束排序，提高效率
		{
			break;
		}
	}
}
void show(int *arr, int len)
{
	assert(arr);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 1, 3, 5, 2, 7, 6, 4, 9, 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	show(arr, len);
	my_qsort(arr, len, sizeof(int), int_cmp);
	show(arr, len);
	my_qsort(arr, len, sizeof(int), int_cmp1);
	show(arr, len);
	return 0;
}
