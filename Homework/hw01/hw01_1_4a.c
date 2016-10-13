#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int max_value = 0;
	int fd;
	int i;

	for (i = 0 ; (fd = open("hw01_1_4a.c", O_RDONLY)) != EOF; i++) ;

	printf("Max open = %d\n", i);
}

