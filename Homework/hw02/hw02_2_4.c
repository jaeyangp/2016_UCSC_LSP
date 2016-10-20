// Homework #2
// Q 2.4

#define _POSIX_SOURCE 1

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int newfd, newfd1;
	int c;

	if (argc == 1) {
		fprintf(stderr, "No input text file!\n");
		exit(1);
	};

	char *rfn = argv[1];
	char *wfn = "my_new_file.txt";

	newfd = open(rfn, O_RDONLY);

	if (newfd < 0) {
		fprintf(stderr, "Error: open %s failed\n", rfn);
		exit(1);
	}

	if (dup2(newfd, 0) != 0) {
		fprintf(stderr, "Error: could not dup2 %s\n", rfn);
		exit(1);
	}

	close(newfd);

	newfd1 = open(wfn, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	if (newfd1 < 0) {
		fprintf(stderr, "Error: open %s failed\n", wfn);
		exit(1);
	}

	if (dup2(newfd1, 1) != 1) {
		fprintf(stderr, "Error: could not dup2 %s\n", wfn);
		exit(1);
	}

	close(newfd1);

	int lc = 0;
	while ((c = getchar()) != EOF) {
		putchar(c);
		
		if (c == '\n')
			lc++;
	}

	fprintf(stderr, "%d lines copied\n", lc);

//	close(0);
//	close(1);
	exit(0);
}

