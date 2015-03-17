#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char **argv)
{
	/*char read from file*/
	int c;
	FILE *fp;

	/*codeeval never 'fails' to open file, no need to bother checking*/
	fp = fopen(argv[1], "r");

	/*keep pulling characters until EOF*/
	while(fgetc(fp) != EOF)
	{

		/*iterators, count of primes found, array to store primes in*/
		int sum, ii, jj, count, *primes;
		/*maximum number and aproximation of how many primes will be found*/
		int max, size;

		/*seek backwards in file, this may not work, dat implementation defined functionality*/
		fseek(fp, -1, SEEK_CUR);
		fscanf(fp, "%i\n", &max);

		/*loose hueristic to overshoot how many primes i will find without being too far off*/
		size = (max/(log10(max)*2)) * 1.1;

		/*malloc an array with size of guess*/
		primes = malloc(size * sizeof(int));
		/*first prime is 2*/
		primes[0] = 2;
		count = 1;
		sum = 0;

		putchar('2');

		/*start at 3, 2 is already known to be prime
		 skip any even number as known to be non-prime*/
		for(ii = 3; ii < max; ii+=2)
		{
			int isPrime = 1;
			/*only need to check already found primes to reduce number of checks*/
			for(jj = 0; jj < count && ii >= (primes[jj]*primes[jj]); jj++)
			{	
				/*can't be a prime if divisible by primes*/
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
