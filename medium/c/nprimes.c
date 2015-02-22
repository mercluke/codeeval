#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char **argv)
{
	int c;
	FILE *fp;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{

		int sum, ii, jj, count, *primes;
		int max, size;

		fseek(fp, -1, SEEK_CUR);
		fscanf(fp, "%i\n", &max);

		size = (max/(log10(max)*2)) * 1.1;

		primes = malloc(size * sizeof(int));
		primes[0] = 2;
		count = 1;
		sum = 0;

		putchar('2');

		for(ii = 3; ii < max; ii+=2)
		{
			int isPrime = 1;
			for(jj = 0; jj < count && ii >= (primes[jj]*primes[jj]); jj++)
			{	
				if(!(ii%primes[jj]))
				{
					isPrime = 0;
					break;
				}
			}
			if(isPrime)
			{
				primes[count++] = ii;

				printf(",%i", ii);
			}
		}

		free(primes);

		putchar('\n');
	}


	return 0;
}