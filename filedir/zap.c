#include <fcntl.h>

#include "apue.h"

int main(int argc, const char *argv[])
{
	int i = 0;
	int fd = 0;
	struct stat statbuf = {0};
	struct timespec times[2] = {0};

	if(argc < 2)
	{
		fprintf(stderr,"Usage %s <file>\n", argv[0]);
		return -1;
	}

	for (i = 1; i < argc; i++)
	{
		if (stat(argv[i], &statbuf) < 0)
		{ /* fetch current times */
			err_ret("%s: stat error", argv[i]);
			continue;
		}
		if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0)
		{ /* truncate */
			err_ret("%s: open error", argv[i]);
			continue;
		}
		times[0] = statbuf.st_atim;
		times[1] = statbuf.st_mtim;
		if (futimens(fd, times) < 0) /* reset times */
		{
			err_ret("%s: futimens error", argv[i]);
		}
		
		close(fd);
	}
	exit(0);
}
