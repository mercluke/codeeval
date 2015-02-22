#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int size = 0;
	FILE *fp;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		size++;
	}

	printf("%i\n", size);

	return 0;
}