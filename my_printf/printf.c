#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <stdarg.h>
#include <assert.h>

void printd(int n)//�����ΰ��ַ������  
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
//		case '%':            //����%ִ��switch���  
//		{
//								 if (*(str + 1) == 'c')    //����ַ�  
//								 {
//									 ch = va_arg(arg, char);
//									 putchar(ch);
//									 str++;                //ָ�����ָ����ƫ��һ����λ  
//								 }
//								 else if (*(str + 1) == 'd')
//								 {
//									 ch = va_arg(arg, char);  //��������ַ�  
//									 printd(ch);
//									 str++;
//								 }
//								 else if (*(str + 1) == 's')//����ַ���  
//								 {
//									 char*p = va_arg(arg, char*);
//									 while (*p)
//									 {
//										 putchar(*p);
//										 p++;
//									 }
//									 str++;                //ָ��ͷһ��������һ���ַ�  
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
		if (*format == '%')  //�ж��Ƿ���%
		{
			format++;
			switch (*format)
			{
			case 's':    //����ַ���
			{
						char *ch = va_arg(arg, char*);
						 while (*ch)
						 {
							 putchar(*ch++);
						 }
						 break;
			}
			case 'c':putchar(va_arg(arg, char));   //����ַ�
				break;
			case 'd': printd(va_arg(arg, int));    //�������
				break;
			case '%':putchar('%');     //���%
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
				puts("\n");     //���\n
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