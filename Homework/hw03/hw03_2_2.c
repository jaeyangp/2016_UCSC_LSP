#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	pid_t my_pid;

	my_pid = getpid();

	printf("Program name = %s, pid = %d\n", argv[0], (int)my_pid);

	char *temp[] = { "/bin/ls", "-l", ".", NULL };
	execv("/bin/ls", temp);

	return 0;
}
