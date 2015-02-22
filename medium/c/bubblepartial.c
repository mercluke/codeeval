#include <stdio.h>
#include <stdlib.h>

void sort(int *list, int count, int iters);

int main(int c, char **argv)
{
	FILE *fp;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		int ii;
		int list[100];
		int count = 0;
		int iters;

		fseek(fp, -1, SEEK_CUR);

		while(fgetc(fp) != '|')
		{
			fseek(fp, -1, SEEK_CUR);

			fscanf(fp, "%i ", &(list[count++]));
		}
		fscanf(fp, " %i\n", &iters);

		sort(list, count, iters);

		for(ii = 0;ii < count; ii++)
		{
			printf("%i ", list[ii]);
		}
		putchar('\n');

	}

	return 0;

}

void sort(int *list, int count, int iters)
{
	int ii = 0, sorted = 0;

	while(!sorted && ii != iters)
	{
		int jj;
		sorted = 1;
		ii++;

		for(jj = 0; jj < count-ii; jj++)
		{
			if(list[jj] > list[jj+1])
			{
				int tmp = list[jj];
				sorted = 0;
				list[jj] = list[jj+1];
				list[jj+1] = tmp;
			}
		}
	}
}