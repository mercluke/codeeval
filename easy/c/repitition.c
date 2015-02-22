#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fp;
	int prev = EOF, curr;

	fp = fopen(argv[1], "r");

	while((curr = fgetc(fp)) != EOF)
	{
		if(curr != prev)
		{
			putchar(curr);
		}
		prev = curr;
	}
	putchar('\n');

	return 0;
}