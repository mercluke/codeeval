#include <stdio.h>

int mod(int n, int m);

int main(int argc, char **argv)
{
	FILE *fp;
	int n, m;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		fseek(fp, -1, SEEK_CUR);

		fscanf(fp, "%i,%i\n", &n, &m);
		printf("%i\n", mod(n,m));
	}
}

int mod(int n, int m)
{
	int ii, ret = n;

	for(ii = 0; ii < n/m; ii++)
	{
		ret -= m;
	}

	return ret;
}