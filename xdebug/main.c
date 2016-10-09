
#include <stdio.h>
#include <stdlib.h>

#include "xdebug.h"


void print_stack()
{
	char buf[1024];
	current_stack(buf, 1024);
	printf("%s \n", buf);
}

void f1()
{
	print_stack();
}

void f2()
{
	f1();
}

void f3()
{
	f2();
}

int main()
{
	f3();
	return 0;
}


