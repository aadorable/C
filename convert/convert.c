#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include "convert.h"

static int status = NULSTAT;

void do_null_stat(FILE* ipf, FILE* opf)
{
	int c = fgetc(ipf);        //��input.c�ж���һ���ַ�
	switch (c)
	{
	case '/':
	{
		int s = fgetc(ipf);    //����һ���ַ���/�������ȡ�ڶ����ַ�
		switch (s)
		{
		case '/':             //����ڶ����ַ���/��ΪC++ģʽ
			fputc('/', opf);
			fputc('/', opf);
			status = CPPSTAT;
			break;
		case '*':             //����ڶ����ַ���*��ΪCģʽ���轫����תΪC++ע�ͷ��
			fputc('/', opf);
			fputc('/', opf);
			status = CSTAT;
			break;
		default:
			ungetc(s, ipf);   //��������ǰ�����������˻ص������ļ��������һ���ַ�
			status = NULSTAT; //����תΪ��ͨģʽ
			break;
		}
	}
		break;
	case EOF:
		status = EOFSTAT;
		break;
	default:
		fputc(c, opf);  //���ַ�д������ļ�
		break;
	}

}

void do_cpp_stat(FILE* ipf, FILE* opf)
{
	int c = fgetc(ipf);
	switch (c)
	{
	case '\n':             //��������ֱ�������output.c�У�֮���ٴΰ���ͨģʽ�����һ���ַ�
		fputc(c, opf);
		status = NULSTAT;
		break;
	case EOF:
		status = EOFSTAT;
		break;
	default:               //������ǰ�������֮ǰ������input.c�ж�ȡ���ַ����뵽output.c��
		fputc(c, opf); 
		status = CPPSTAT;
		break;
	}
}

void do_c_stat(FILE* ipf, FILE* opf)
{
	int c = fgetc(ipf);
	switch (c)
	{
	case '\n':              //��������ֱ�������output.c�У�֮������//��Ϊ�ڶ��е�ע��ת��
		fputc('\n', opf);
		fputc('/', opf);
		fputc('/', opf);
		status = CSTAT;
		break;
	case '*':
	{
		int s = fgetc(ipf);     //������*�������¸��ַ�
		switch (s)
		{
		case '/':              //���ڶ����ַ�Ϊ/�����������ַ�
		{
			int n = fgetc(ipf);
			if (n == ' ')       //�������ո����ڵڶ����е�һ���ַ���ӦΪ�ո�
			{
				fputc(' ', opf);
				fputc('\n', opf);
			}
			else if (n == '\n')    //��Ϊ���з���ֱ���������
			{
				fputc('\n', opf);
			}
			else                  
			{
				fputc('\n', opf);
				ungetc(n, ipf);    //��������ǰ�����������˻ص������ļ��������һ���ַ�
			}
			status = NULSTAT;
			break;
		}
		case EOF:
			status = EOFSTAT;
			break;
		default:
			ungetc(s, ipf);     //��������ǰ�����������˻ص������ļ��������һ���ַ�
			status = CSTAT;
			break;
		}
		break;
	}
	case EOF:
		status = EOFSTAT;
		break;
	default:
		fputc(c, opf);         //������ǰ�������֮ǰ������input.c�ж�ȡ���ַ����뵽output.c��
		break;
	}
}

static void convert_work(FILE* ipf, FILE* opf)
{
	while (status != EOFSTAT)
	{
		switch (status)
		{
		case NULSTAT:
			do_null_stat(ipf, opf);    //ִ����ͨģʽ
			break;
		case CPPSTAT:
			do_cpp_stat(ipf, opf);     //ִ��C++ģʽ
			break;
		case CSTAT:
			do_c_stat(ipf, opf);       //ִ��Cģʽ
			break;
		case EOFSTAT:
			break;
		default:
			break;
		}
	}
}

void convert_main()
{
	FILE* ipf = fopen(INPUT, "r");
	FILE* opf = fopen(OUTPUT, "w");
	if (ipf == NULL || opf == NULL)
	{
		fprintf(stderr, "open file erro\n");
		exit(1);
	}
	convert_work(ipf, opf);
	fclose(ipf);
	fclose(opf);
}