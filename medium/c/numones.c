#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		int i, hits = 0;
		fseek(fp, -1, SEEK_CUR);
		
		fscanf(fp, "%i\n", &i);

		while(i)
		{
			if(i&1)
			{
				hits++;
			}
			i >>= 1;
		}
		printf("%i\n", hits);
	}
}