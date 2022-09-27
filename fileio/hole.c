#include <fcntl.h>

#include "apue.h"

#define MAX_OFFSET_BYTES (10240)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(int argc, const char * argv[])
{
	int fd = 0;

	if ((fd = creat("file.hole", FILE_MODE)) < 0)
	{
		err_sys("creat error");
	}

	if (write(fd, buf1, 10) != 10)
	{
		err_sys("buf1 write error");
	}

	/* offset now = 10 */

	if (lseek(fd, MAX_OFFSET_BYTES, SEEK_SET) == -1)
	{
		err_sys("lseek error");
	}

	/* offset now = MAX_OFFSET_BYTES */

	if (write(fd, buf2, 10) != 10)
	{
		err_sys("buf2 write error");
	}

	/* offset now = MAX_OFFSET_BYTES + 10  */

	exit(0);
}
