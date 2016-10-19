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


int main(int argc, char **argv)
{
	int newfd;
	int nchar = 0;
	int nword = 0;
	int nline = 0;
	int c;

	if (argc == 1) {
		fprintf(stderr, "No input text file!\n");
		exit(1);
	};

	char *rfn = argv[1];

	// stdin redirection
	close(0);
	newfd = open(rfn, O_RDONLY);

	if (newfd < 0) {
		fprintf(stderr, "Error: open `%s' failed: %s\n", rfn, strerror(errno));
		exit(1);
	}

	while ((c = getchar()) != EOF) {
		putchar(c);
	}

	close(newfd);
	exit(0);
}

