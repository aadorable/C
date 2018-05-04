#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <stdarg.h>
#include <assert.h>

void printd(int n)//把整形按字符型输出  
{
	if (n < 0)
	{
		putchar('-');
	}
	if (n)
	{
		printd(n / 10);
		putchar(n % 10 + '0');
	}
}

//void my_printf(char* str, ...)
//{
//	int ch;
//	va_list arg;
//	va_start(arg, str);
//	while (*str)
//	{
//		switch (*str)
//		{
//		case '%':            //遇到%执行switch语句  
//		{
//								 if (*(str + 1) == 'c')    //输出字符  
//								 {
//									 ch = va_arg(arg, char);
//									 putchar(ch);
//									 str++;                //指针变量指向下偏移一个单位  
//								 }
//								 else if (*(str + 1) == 'd')
//								 {
//									 ch = va_arg(arg, char);  //输出整形字符  
//									 printd(ch);
//									 str++;
//								 }
//								 else if (*(str + 1) == 's')//输出字符串  
//								 {
//									 char*p = va_arg(arg, char*);
//									 while (*p)
//									 {
//										 putchar(*p);
//										 p++;
//									 }
//									 str++;                //指向头一变量的下一个字符  
//								 }
//								 else
//									 putchar('%');
//								 break;
//		}
//		default:
//		{
//				   putchar(*str);
//				   break;
//		}
//		}
//		str++;
//	}
//	va_end(arg);
//}

void my_printf(char* format, ...)
{
	va_list arg;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')  //判断是否是%
		{
			format++;
			switch (*format)
			{
			case 's':    //输出字符串
			{
						char *ch = va_arg(arg, char*);
						 while (*ch)
						 {
							 putchar(*ch++);
						 }
						 break;
			}
			case 'c':putchar(va_arg(arg, char));   //输出字符
				break;
			case 'd': printd(va_arg(arg, int));    //输出整形
				break;
			case '%':putchar('%');     //输出%
				break;
			default: puts("format error!\n");
				return;
			}
			format++;
		}
		else if (*format == '\\')   
		{
			format++;
			if (*format == 'n')
			{
				puts("\n");     //输出\n
			}
		}
		else
		{
			putchar(*format);
			format++;
		}
	}
	va_end(arg);
}
int main()
{
	my_printf("%s %c%c%c %d\n", "hello", 'b', 'i', 't', 100);
	system("pause");
	return 0;
}