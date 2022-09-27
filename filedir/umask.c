#include <fcntl.h>

#include "apue.h"

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

#define FILE1 "foo"
#define FILE2 "bar"

int main(int argc, const char *argv[])
{
	char buff[64] = {0};

	umask(0);

	if (creat(FILE1, RWRWRW) < 0)
	{
		err_sys("creat error FILE1");
	}

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	
	if (creat(FILE2, RWRWRW) < 0)
	{
		err_sys("creat error for FILE2");
	}
	
	memset(buff,0,sizeof(buff));
	sprintf(buff,"ls -l %s %s", FILE1,FILE2);

	system(buff);
	
	remove(FILE1);
	remove(FILE2);

	exit(0);
}
