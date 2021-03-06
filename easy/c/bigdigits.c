#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printInt(char *str);

char digits[10][6][5] = {
		{
			{"-**-"},
			{"*--*"},
			{"*--*"},
			{"*--*"},
			{"-**-"},
			{"----"}
		},
		{
			{"--*-"},
			{"-**-"},
			{"--*-"},
			{"--*-"},
			{"-***"},
			{"----"}
		},
		{
			{"***-"},
			{"---*"},
			{"-**-"},
			{"*---"},
			{"****"},
			{"----"}
		},
		{
			{"***-"},
			{"---*"},
			{"-**-"},
			{"---*"},
			{"***-"},
			{"----"}
		},
		{
			{"-*--"},
			{"*--*"},
			{"****"},
			{"---*"},
			{"---*"},
			{"----"}
		},
		{
			{"****"},
			{"*---"},
			{"***-"},
			{"---*"},
			{"***-"},
			{"----"}
		},
		{
			{"-**-"},
			{"*---"},
			{"***-"},
			{"*--*"},
			{"-**-"},
			{"----"}
		},
		{
			{"****"},
			{"---*"},
			{"--*-"},
			{"-*--"},
			{"-*--"},
			{"----"}
		},
		{
			{"-**-"},
			{"*--*"},
			{"-**-"},
			{"*--*"},
			{"-**-"},
			{"----"}
		},
		{
			{"-**-"},
			{"*--*"},
			{"-***"},
			{"---*"},
			{"-**-"},
			{"----"}
		}
	};

void printInt(char *str)
{
	int ii, jj;
	int len = strlen(str);

	for(ii = 0; ii < 6; ii++)
	{
		for(jj = 0; jj < len; jj++)
		{
			printf("%s-", digits[str[jj]-'0'][ii]);
		}
		putchar('\n');
	}



}

int main(int argc, char **argv)
{
	FILE *fp;

	int c, i;
	char* str;

	fp = fopen(argv[1], "r");

	while((c = fgetc(fp)) != EOF)
	{
		fseek(fp, -1, SEEK_CUR);
		
		str = calloc(sizeof(char), 32);
		i = 0;

		while((c = fgetc(fp)) != '\n' && c != EOF)
		{
			if(c >= '0' && c <= '9')
			{
				str[i++] = c;
			}
		}

		printInt(str);

		free(str);

	}

	return 0;
}