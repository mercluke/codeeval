#include <stdio.h>

int high(int c);
int low(int c);

int main(int argc, char **argv)
{
	FILE *fp;
	int up = 1;
	int curr;

	fp = fopen(argv[1], "r");

	while((curr = fgetc(fp)) != EOF)
	{
		if((curr >= 'a' && curr <= 'z') || (curr >= 'A' && curr <= 'Z'))
		{
			if(up)
			{
				putchar(high(curr));
			}	
			else
			{
				putchar(low(curr));
			}
			up = 1-up;
		}
		else
		{
			putchar(curr);
			if(curr == '\n') up = 1;
		}
	}
	putchar('\n');

	return 0;
}

int high(int c)
{
	if(c >= 'a' && c <= 'z')
	{
		return c-32;
	}
	return c;
}

int low(int c)
{
	if(c >= 'A' && c <= 'Z')
	{
		return c+32;
	}
	return c;
}