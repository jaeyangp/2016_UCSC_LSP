// Homework #2
// Q 2.2

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
	int c;

	if (argc == 1) {
		fprintf(stderr, "No input text file!\n");
		exit(1);
	};

	char *rfn;
	int i;

	// stdin redirection
	close(0);

	for (i = 0; i < (argc-1); i++) {
		rfn = argv[i+1];

		newfd = open(rfn, O_RDONLY);

		if (newfd < 0) {
			fprintf(stderr, "Error: open `%s' failed: %s\n", rfn, strerror(errno));
			exit(1);
		}

		while ((c = getchar()) != EOF) {
			putchar(c);
		}

		close(newfd);

	}

	exit(0);
}

