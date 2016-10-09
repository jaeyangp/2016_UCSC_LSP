// mismatch between newargv[0] & first argument to execve()

#include <stdio.h>

int main(int argc, char **argv, char **envp) {

	int i=0;

	char *newargv[16];
	char *newenvp[16];

	newenvp[0]=0;

	newargv[i++]="Not a program";
	newargv[i++]="-f";
	newargv[i++]=0;

  if (!strcmp(argv[1],"app"))
		execve("./ex1app", newargv, newenvp);
	else
		execve("./ex.sh", newargv, newenvp);

	fprintf(stderr,"Hello World!\n");  // Code not reached!!
}
	
