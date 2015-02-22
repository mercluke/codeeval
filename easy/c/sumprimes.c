#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sum, ii, jj, count, *primes;

	primes = calloc(1000, sizeof(int));
	primes[0] = 2;
	count = 1;
	sum = 2;

	for(ii = 3; count < 1000; ii++)
	{
		int isPrime = 1;
		for(jj = 0; jj < count; jj++)
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
			sum += ii;
		}
	}

	printf("%i\n", sum);
	return 0;
}