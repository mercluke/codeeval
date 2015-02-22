#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void toBinary(unsigned long val);

int main(int argc, char **argv)
{
	FILE *fp;
	int c;

	fp = fopen(argv[1], "r");

	while((c =fgetc(fp)) != EOF)
	{
		int val;
		if(c >= '0' && c <= '9')
		{
			fseek(fp, -1, SEEK_CUR);

			fscanf(fp, "%i\n", &val);

			toBinary(val);
		}
	}
}

void toBinary(unsigned long val)
{
	if(val != 0)
	{
		int power = 0;

		while(pow(2,power) <= val)
		{
			power++;
		}
		while(power > 0)
		{
			int sub = pow(2, power-1);
			if(sub <= val)
			{
				val-=sub;
				putchar('1');
			}
			else
			{
				putchar('0');
			}
			power--;
		}
	}
	else
	{
		putchar('0');
	}
	putchar('\n');

}