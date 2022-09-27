#include <fcntl.h>

#include "apue.h"

int main(int argc, const char *argv[])
{
	int fd = 0;

	if (argc != 2)
	{
		err_quit("Usage: a.out <pathname>");
	}

	if (access(argv[1], R_OK) < 0)
	{
		err_ret("access error for %s", argv[1]);
	}
	else
	{
		printf("read access OK\n");
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		err_ret("open error for %s", argv[1]);
	}
	else
	{
		printf("open for reading OK\n");
	}

	close(fd);
	
	exit(0);
}
