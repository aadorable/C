#ifndef __COUNTER_H__
#define __COUNTER_H__

enum{
	NULSTAT,     //��ͨģʽ
	CSTAT,       //Cģʽ
	CPPSTAT,     //C++ģʽ
	EOFSTAT,     //EOFģʽ
};

#define INPUT "input.c"
#define OUTPUT "output.c"

void convert_main();

#endif