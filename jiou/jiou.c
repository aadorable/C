#include <stdio.h>
#include <assert.h>

static exchange(int *p, int *q)
{
	*p ^= *q;
	*q ^= *p;
	*p ^= *q;
}
void Exchange(int arr[], int sz)
{
	assert(arr);
	assert(sz > 0);
	int *p = arr;
	int *q = arr + sz - 1;
	while (p < q)
	{
		if (!(*p & 1) && (*q & 1))        //偶数的最后一个bit位一定是0；奇数的最后一个bit位一定是1；
		{
			exchange(p, q);
			p++, q--;
		}
		if (*p & 1)
		{
			p++;
		}
		if (!(*q & 1))
		{
			q--;
		}
	}
}
static void Show(int arr[], int sz)    
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Show(arr, sz);
	Exchange(arr, sz);
	Show(arr, sz);
	return 0;
}
