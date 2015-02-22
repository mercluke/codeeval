#include <stdio.h>
#include <math.h>

int reverse(int num);
int isPalin(int num);

int main(int argc, char **argv)
{
	FILE *fp;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		int num, ii = 0;

		fseek(fp, -1, SEEK_CUR);
		fscanf(fp, "%i\n", &num);

		while(!isPalin(num))
		{
			ii++;
			num = reverse(num) + num;
		}

		printf("%i %i\n", ii, num);

	}

	
	return 0;
}

int reverse(int num)
{
	int ii, sum = 0, len = 0;

	for(ii = 0; num > pow(10, ii); ii++);

	for(len = --ii; ii >= 0; ii--)
	{
		sum += (num%(int)(pow(10, ii+1))/(int)(pow(10,ii)))*(pow(10, len-ii));
	}

	return sum;
}

int isPalin(int num)
{
	int ret = 0;
	
	if(num == reverse(num))
	{
		ret = 1;
	}

	return ret;
}