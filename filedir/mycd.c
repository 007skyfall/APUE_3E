#include "apue.h"

int main(int argc, const char *argv[])
{
	if (chdir("/tmp") < 0)
	{
		err_sys("chdir failed");
	}

	system("pwd");
	printf("chdir to /tmp succeeded\n");
	
	exit(0);
}
