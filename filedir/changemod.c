#include "apue.h"

int main(int argc, const char *argv[])
{
	struct stat statbuf = {0};

	/* turn on set-group-ID and turn off group-execute */

	system("touch /tmp/a /tmp/b");

	if (stat("/tmp/a", &statbuf) < 0)
	{
		err_sys("stat error for foo");
	}

	if (chmod("/tmp/a", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
	{
		err_sys("chmod error for foo");
	}

	/* set absolute mode to "rw-r--r--" */

	if (chmod("/tmp/b", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
	{
		err_sys("chmod error for bar");
	}

	exit(0);
}
