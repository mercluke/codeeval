#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isHappy(int num);

int main(int argc, char **argv)
{
	FILE *fp;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		int num;

		fseek(fp, -1, SEEK_CUR);

		fscanf(fp, "%i\n", &num);

		printf("%i\n", isHappy(num));

	}

	return 0;
}

int isHappy(int num)
{
	if(num == 4)
	{
		return 0;
	}
	else if (num == 1)
	{
		return 1;
	}
	
	int sum = 0;

	while(num > 0)
	{
		int digit = num%10;
		sum += pow(digit, 2);
		num /= 10;
	}

	return isHappy(sum);

}