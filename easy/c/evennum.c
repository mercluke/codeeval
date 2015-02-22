#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		int val;
		fseek(fp, -1, SEEK_CUR);

		fscanf(fp, "%i\n", &val);

		printf("%i\n", 1-(val%2));
	}

	return 0;
}