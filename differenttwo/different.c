#include <stdio.h>
#include <assert.h>

void Find_different(int arr[], int len)
{
	assert(arr);
	assert(len > 2);
	int i = 1;
	int num = arr[0];
	while (i < len)
	{
		num ^= arr[i];     //将所有数异或
		i++;
	}
	int flag = 1;
	i = 0;
	while (i < 32)
	{
		if (num & (flag << i))     //判断某比特位是否为1
		{
			flag <<= i;
			break;
		}
		i++;
	}
	i = 0;
	int data1 = 0;
	int data2 = 0;
	for (i = 0; i < len; i++)      //根据指定比特位不同将其分组
	{
		if (arr[i] & flag)
		{
			data1 ^= arr[i];
		}
		else
		{
			data2 ^= arr[i];
		}
	}
	printf("different data= %d %d\n",data1, data2);
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 7, 8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Find_different(arr, len);
	return 0;
}
