#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fp;
	int prev = ' ', curr;

	fp = fopen(argv[1], "r");

	while((curr = fgetc(fp)) != EOF)
	{
		if((prev == '\n' || prev == ' ') && curr >= 'a' && curr <= 'z')
		{
			putchar(curr-32);
		}
		else
		{
			putchar(curr);
		}
		prev = curr;
	}
	putchar('\n');

	return 0;
}