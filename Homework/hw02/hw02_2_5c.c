// Q 2.5C

#define _POSIX_SOURCE 1

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <time.h>

int main(int argc, char **argv)
{
	DIR *dirp;
	struct dirent *dp;
	struct stat *statinfo;
	char *dir_name;

	int long_list = 0;

	if (argc == 1)
		dir_name = ".";
	else if (strcmp(argv[1], "-l")==0){
		dir_name = argv[2];
		long_list = 1;
	} else {
		dir_name = argv[1];
	}

	if (long_list) {
		statinfo = (struct stat *)malloc(sizeof(struct stat));

		if (stat(dir_name, statinfo) != 0)
			fprintf(stderr, "stat() failed: %s\n", strerror(errno));
		else {
			printf("%07o\t%s\t%10lu\t%s\n", statinfo->st_mode, dir_name, statinfo->st_size, ctime(&statinfo->st_atime));
		}

		exit(0);
	}
	else {
		dirp = opendir(dir_name);

		if (dirp == NULL) {
			fprintf(stderr, "Error: can't open '%s'\n", dir_name);
			exit(1);
		}

		while ((dp = readdir(dirp)) != NULL) {
			if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) 
				continue;
			else
				printf("%s \n", dp->d_name);
		}

		closedir(dirp);
	}
}

