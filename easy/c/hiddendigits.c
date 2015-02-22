#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp;
	int c;

	fp = fopen(argv[1], "r");

	while((c = fgetc(fp) != EOF))
	{
		int count = 0;
		fseek(fp, -1, SEEK_CUR);

		while(c != '\n' && c != EOF)
		{
			if(c >= 'a' && c <= 'j')
			{
				c -= 'a';
				c += '0';
			}
			if(c >= '0' && c <= '9')
			{
				count++;
				putchar(c);
			}
			c = fgetc(fp);
		}
		if(!count)
		{
			printf("NONE");
		}
		putchar('\n');
	}

}