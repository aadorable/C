#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>             //ʹ�õ�ǰʱ��������
void menu()
{
	printf("                                      \n");
	printf("**************************************\n");
	printf("**********1.play******0.exit**********\n");
	printf("**************************************\n");
}
void game()
{
	int num = 0;
	int n = 0;
	num = rand() % 100 + 1;             //������1��100֮����������rand���������ǲ���α�����
	while (1)
	{
		printf("������µ����֣�");
		scanf("%d", &n);
		if (n > num)
		{
			printf("�´���!\n");
		}
		else if (n < num)
		{
			printf("��С��!\n");
		}
		else 
		{
			printf("��ϲ�㣬�¶���!\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));        //������������ӣ�srand������������������ĳ�ʼ������
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			break;
		default:
			printf("ѡ��������������룡\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}