#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int armstrong(int num);


int main(int argc, char **argv)
{
	FILE *fp;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		int num;
		fseek(fp, -1, SEEK_CUR);

		fscanf(fp, "%i\n", &num);

		if(armstrong(num))
		{
			printf("True\n");
		}
		else
		{
			printf("False\n");
		}
	}

	return 0;
}

int armstrong(int num)
{
	int len = 0;
	int power = 0;
	int sum = 0;
	int orig = num;

	while(pow(10, power) <= num)
	{
		power++;

	}

	len = power;

	while(num > 0)
	{
		int digit = num/(pow(10, len));
		num -= digit*pow(10, len);
		sum += pow(digit, power);
		len--;
	}

	return (sum == orig);
}