// #1. Global un-initialized array

#include <stdio.h>

int myarray[50000];

int main(void)
{
	myarray[0] = 1;

	return 0;
}

