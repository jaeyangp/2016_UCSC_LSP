// Q2.3

#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("Maximum number of open files = %ld\n", sysconf(_SC_OPEN_MAX));

	return 0;
}
