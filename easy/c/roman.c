#include <stdio.h>
#include <stdlib.h>

void printRoman(int num);

int main(int argc, char **argv)
{
	FILE *fp;
	int num;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		fseek(fp, -1, SEEK_CUR);

		fscanf(fp, "%i\n", &num);
		printRoman(num);
	}

	return 0;
}

void printRoman(int num)
{
	int M, D, C, L, X, V, I, ii;

	M = num / 1000;
	num -= M*1000;
	D = num / 500;
	num -= D*500;
	C = num / 100;
	num -= C*100;
	L = num / 50;
	num -= L*50;
	X = num / 10;
	num -= X*10;
	V = num / 5;
	num -= V*5;
	I = num;

	for(ii = 0; ii < M; ii++)
	{
		putchar('M');
	}
	if(C != 4)
	{
		for(ii = 0; ii < D; ii++)
		{
			putchar('D');
		}
		for(ii = 0; ii < C; ii++)
		{
			putchar('C');
		}
	}
	else
	{
		if(D)
		{
			printf("CM");
		}
		else
		{
			printf("CD");
		}
	}
	if(X != 4)
	{
		for(ii = 0; ii < L; ii++)
		{
			putchar('L');
		}
		for(ii = 0; ii < X; ii++)
		{
			putchar('X');
		}
	}
	else
	{
		if(L)
		{
			printf("XC");
		}
		else
		{
			printf("XL");
		}
	}
	if(I != 4)
	{
		for(ii = 0; ii < V; ii++)
		{
			putchar('V');
		}
		for(ii = 0; ii < I; ii++)
		{
			putchar('I');
		}
	}
	else
	{
		if(V)
		{
			printf("IX");
		}
		else
		{
			printf("IV");
		}
	}

	putchar('\n');
}