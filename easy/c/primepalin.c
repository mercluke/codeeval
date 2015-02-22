#include <stdio.h>
#include <stdlib.h>

int isPal(int num);

int main()
{
	int sum, ii, jj, count, *primes;

	primes = calloc(170, sizeof(int));
	primes[0] = 2;
	count = 1;
	sum = 0;

	for(ii = 3; ii < 1000; ii++)
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
		}
	}

	for(ii = count-1; ii >= 0; ii--)
	{
		if(isPal(primes[ii]))
		{
			printf("%i\n", primes[ii]);
			break;
		}
	}


	return 0;
}

int isPal(int num)
{
	int ii, len;	
	int nums[3];

	for(ii = 0; num; ii++)
	{
		nums[ii] = num%10;
		num /= 10;
	}
	len = ii;
	for(ii = 0; ii < len/2; ii++)
	{
		if(nums[ii] != nums[len-1-ii]) return 0;
	}

	return 1;
}