#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include "convert.h"

static int status = NULSTAT;

void do_null_stat(FILE* ipf, FILE* opf)
{
	int c = fgetc(ipf);        //从input.c中读出一个字符
	switch (c)
	{
	case '/':
	{
		int s = fgetc(ipf);    //若第一个字符是/则继续读取第二个字符
		switch (s)
		{
		case '/':             //如果第二个字符是/则为C++模式
			fputc('/', opf);
			fputc('/', opf);
			status = CPPSTAT;
			break;
		case '*':             //如果第二个字符是*则为C模式，需将其风格转为C++注释风格
			fputc('/', opf);
			fputc('/', opf);
			status = CSTAT;
			break;
		default:
			ungetc(s, ipf);   //若不符合前两个条件则退回到输入文件，检查下一个字符
			status = NULSTAT; //继续转为普通模式
			break;
		}
	}
		break;
	case EOF:
		status = EOFSTAT;
		break;
	default:
		fputc(c, opf);  //将字符写入输出文件
		break;
	}

}

void do_cpp_stat(FILE* ipf, FILE* opf)
{
	int c = fgetc(ipf);
	switch (c)
	{
	case '\n':             //遇到换行直接输出到output.c中，之后再次按普通模式检查下一个字符
		fputc(c, opf);
		status = NULSTAT;
		break;
	case EOF:
		status = EOFSTAT;
		break;
	default:               //在遇到前两次情况之前，将从input.c中读取的字符输入到output.c中
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
	case '\n':              //遇到换行直接输出到output.c中，之后输入//做为第二行的注释转换
		fputc('\n', opf);
		fputc('/', opf);
		fputc('/', opf);
		status = CSTAT;
		break;
	case '*':
	{
		int s = fgetc(ipf);     //若遇到*则需检查下个字符
		switch (s)
		{
		case '/':              //若第二个字符为/则还需检查下面字符
		{
			int n = fgetc(ipf);
			if (n == ' ')       //若遇到空格则在第二行中第一个字符不应为空格
			{
				fputc(' ', opf);
				fputc('\n', opf);
			}
			else if (n == '\n')    //若为换行符则直接输出换行
			{
				fputc('\n', opf);
			}
			else                  
			{
				fputc('\n', opf);
				ungetc(n, ipf);    //若不符合前两个条件则退回到输入文件，检查下一个字符
			}
			status = NULSTAT;
			break;
		}
		case EOF:
			status = EOFSTAT;
			break;
		default:
			ungetc(s, ipf);     //若不符合前两个条件则退回到输入文件，检查下一个字符
			status = CSTAT;
			break;
		}
		break;
	}
	case EOF:
		status = EOFSTAT;
		break;
	default:
		fputc(c, opf);         //在遇到前两次情况之前，将从input.c中读取的字符输入到output.c中
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
			do_null_stat(ipf, opf);    //执行普通模式
			break;
		case CPPSTAT:
			do_cpp_stat(ipf, opf);     //执行C++模式
			break;
		case CSTAT:
			do_c_stat(ipf, opf);       //执行C模式
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