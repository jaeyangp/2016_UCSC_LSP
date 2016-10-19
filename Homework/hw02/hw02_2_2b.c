// Homework #2
// Q 2.2B

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
	int line_flag = 0;

	// stdin redirection
	close(0);

	for (i = 1; i < argc; i++) {
		if (!strcmp(argv[1], "-l")) { 
			if (i > (argc-2))
				break;

			rfn = argv[i+1];
			line_flag = 1;
		} else {
			rfn = argv[i];
		}

		newfd = open(rfn, O_RDONLY);

		if (newfd < 0) {
			fprintf(stderr, "Error: open `%s' failed: %s\n", rfn, strerror(errno));
			exit(1);
		}

		if (line_flag) {
			printf("# ");
			while ((c = getchar()) != EOF) {
				if (c == '\n') {
					putchar('\n');
					putchar('#');
					putchar(' ');
				} else 
					putchar(c);
			}
		} else {
			while ((c = getchar()) != EOF) {
				putchar(c);
			}
		}

		close(newfd);
	}

	putchar('\n');

	exit(0);
}

