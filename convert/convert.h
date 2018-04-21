#ifndef __COUNTER_H__
#define __COUNTER_H__

enum{
	NULSTAT,     //普通模式
	CSTAT,       //C模式
	CPPSTAT,     //C++模式
	EOFSTAT,     //EOF模式
};

#define INPUT "input.c"
#define OUTPUT "output.c"

void convert_main();

#endif