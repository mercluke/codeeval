#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fp;
	int curr;

	fp = fopen(argv[1], "r");

	while((curr = fgetc(fp)) != EOF)
	{
		

		if(curr >= 'a' && curr <= 'z')
		{
			putchar(curr-32);
		}
		else if(curr >= 'A' && curr <= 'Z')
		{
			putchar(curr+32);
		}
		else
		{
			putchar(curr);
		}
	}

	return 0;
}
