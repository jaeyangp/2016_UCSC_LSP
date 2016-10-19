// Q 2.5B

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char **argv)
{
	DIR *dirp;
	struct dirent *dp;
	char *dir_name;

	if (argc == 1)
		dir_name = ".";
	else
		dir_name = argv[1];

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

