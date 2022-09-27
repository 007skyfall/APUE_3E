#include "apue.h"

int main(int argc, const char *argv[])
{
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
	{
		printf("cannot seek\n");
		perror("lseek");
	}
	else
	{
		printf("seek OK\n");
	}

	exit(0);
}
