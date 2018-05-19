#include <stdio.h>
#include <assert.h>

////容易找出其规律为喝2*N-1瓶
//#define MONEY 20
//int main()
//{
//	printf("drink = %d\n", 2 * MONEY - 1);
//	system("pause");
//	return 0;
//}

int drink(int money)
{
	assert(money > 0);
	int num = money;
	int empty = money;
	while (empty > 1)
	{
		num += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	return num;
}
int main()
{
	int money = 0;
	printf("please input your money:");
	scanf("%d", &money);
	int num = drink(money);
	printf("you can drink %d bottles of water!\n", num);
	return 0;
}
