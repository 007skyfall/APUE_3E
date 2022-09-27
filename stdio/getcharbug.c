#include <stdio.h>

int main(int argc, const char *argv[])
{
	char c = 0;

	while ((c = getchar()) != EOF)
	{
		putchar(c);
	}
	
	return 0;
}
