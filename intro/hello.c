#include "apue.h"

int main(int argc, const char *argv[])
{
	printf("hello world from process ID %ld\n", (long)getpid());

	exit(0);
}
