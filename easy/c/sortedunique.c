#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fp;
	int curr;

	fp = fopen(argv[1], "r");

	while((curr = fgetc(fp)) != EOF)
	{
		fseek(fp, -1, SEEK_CUR);

		int prev = EOF;
		while((curr = fgetc(fp)) != '\n' && curr != EOF)
		{
			if(curr != ',')
			{
				fseek(fp, -1, SEEK_CUR);

				fscanf(fp, "%i,", &curr);

				if(curr != prev)
				{
					if(prev != EOF)
					{
						putchar(',');
					}
					printf("%i", curr);
				}
				prev = curr;
			}
		}
		putchar('\n');
	}
	

	return 0;
}