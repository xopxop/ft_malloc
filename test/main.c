#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int page_size = getpagesize();
	printf("Page size: %d\n", page_size);
	return (0);
}
