#include <stdio.h>

int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 0 };
	int num = arr[0];
	int i = 0;
	for (i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		num ^= arr[i];
	}
	printf("different number is %d\n", num);
	return 0;
}
