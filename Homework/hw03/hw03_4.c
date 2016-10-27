#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("Maximum number of processed forked = %ld\n", sysconf(_SC_CHILD_MAX));
}

