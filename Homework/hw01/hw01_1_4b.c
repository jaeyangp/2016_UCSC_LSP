#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int main()
{
	int max_value;

	max_value = sysconf(_SC_OPEN_MAX);
	printf("SC_OPEN_MAX = %d\n", max_value);
}

