#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp;
	int c;

	fp = fopen(argv[1], "r");

	while((c = fgetc(fp)) != EOF)
	{
		int sum;
		int sumodd = 0;
		int sumeven = 0;
		int odd = 0;

		while(c != EOF && c != '\n')
		{
			if(c != ' ')
			{
				if(odd)
				{
					int val = ((c-'0')*2)/10;
					sumodd += (c-'0');
					sumeven += val;
					sumeven += ((c-'0')*2)-(val*10);
				}
				else
				{
					int val = ((c-'0')*2)/10;

					sumeven+=(c-'0');
					sumodd += val;
					sumodd += ((c-'0')*2)-(val*10);
				}
				odd = 1-odd;
			}

			c = fgetc(fp);
		}

		if(odd)
		{
			sum = sumeven;
		}
		else
		{
			sum = sumodd;
		}

		if(sum%10)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
		}
	}

	return 0;
}