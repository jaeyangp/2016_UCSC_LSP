// #2. Global initialized array

#include <stdio.h>

int myarray[50000] = {1};

int main(void)
{
	myarray[0] = 1;

	return 0;
}

