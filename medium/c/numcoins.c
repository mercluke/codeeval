#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		int val;
		int min = 0;
		fseek(fp, -1, SEEK_CUR);

		fscanf(fp, "%i\n", &val);

		while(val-5 >= 0)
		{
			val-=5;
			min++;
		}
		while(val-3 >= 0)
		{
			val-=3;
			min++;
		}
		while(val-1 >= 0)
		{
			val-=1;
			min++;
		}
		printf("%i\n", min);
	}
	return 0;
}