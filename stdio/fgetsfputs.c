#include "apue.h"

int main(int argc, const char *argv[])
{
	char buf[MAXLINE] = {0};

	while (fgets(buf, MAXLINE, stdin) != NULL)
	{
		if (fputs(buf, stdout) == EOF)
		{
			err_sys("output error");
		}
	}

	if (ferror(stdin))
	{
		err_sys("input error");
	}

	exit(0);
}
