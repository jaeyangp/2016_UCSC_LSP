// #3. Stack un-initialized array

#include <stdio.h>

int main(void)
{
	int myarray[50000];

	myarray[0] = 1;

	return 0;
}

