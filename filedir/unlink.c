#include <fcntl.h>

#include "apue.h"

#define SRC_FILE "temp"
#define DST_FILE "temp_h"

int main(int argc, const char *argv[])
{
	char buff[64] = {0};

	memset(buff, 0, sizeof(buff));

	if (open(SRC_FILE, O_RDWR | O_CREAT, 0664) < 0)
	{
		err_sys("open error");
	}

	if (link(SRC_FILE, DST_FILE) < 0)
	{
		err_sys("link error");
	}

	printf("file will be unlinked\n");
	sprintf(buff, "ls -li %s %s ", SRC_FILE, DST_FILE);
	system(buff);

	if (unlink(DST_FILE) < 0)
	{
		err_sys("unlink error");
	}

	if (remove(SRC_FILE) < 0)
	{
		err_sys("remove error");
	}

	exit(0);
}
