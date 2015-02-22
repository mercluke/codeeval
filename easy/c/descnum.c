#include <stdio.h>
#include <stdlib.h>

int isDesc(int i);

int main(int argc, char** argv)
{
	FILE *fp;
	int i;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		fseek(fp, -1, SEEK_CUR);

		fscanf(fp, "%i\n", &i);
		printf("%i\n", isDesc(i));
	}

	return 0;
}

int isDesc(int i)
{
	int *nums, *digits = calloc(sizeof(int), 10);
	int len = 0, cur = i, ii;

	while(cur/=10)
	{
		len++;
	}

	nums = malloc(sizeof(int) * len+1);

	for(ii = len; ii >= 0; ii--)
	{
		nums[ii] = i%10;
		digits[i%10]++;
		i/=10;
	}

	for(ii = 0; ii < len; ii++)	
	{
		if(digits[ii] != nums[ii])
		{
			return 0;
		}
	}

	return 1;

}