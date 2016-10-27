#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int i;

	pid = fork();

	if (pid < 0) {
		perror("fork failed");
		return -1;
	}
	
	if (pid == 0) {
		for (i = 0; i < 5; i++) {
			sleep(10);
			printf("(pid: %d) Hello World!\n\n", (int)getpid());
		}
	} else {
		exit (1);
	}


	return 0;
}

