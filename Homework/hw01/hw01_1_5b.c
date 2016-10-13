#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int main()
{
	int clock_tck;

	clock_tck = sysconf(_SC_CLK_TCK);
	printf("Clock Ticks = %d\n", clock_tck);
}

