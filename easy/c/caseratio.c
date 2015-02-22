#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fp;
	int low, high, curr;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		fseek(fp, -1, SEEK_CUR);
		low = high = 0;
		
		while((curr = fgetc(fp)) != '\n' && curr != EOF)
		{
			if(curr >= 'a' && curr <= 'z')
			{
				low++;
			}
			else if(curr >= 'A' && curr <= 'Z')
			{
				high++;
			}
		}
		printf("lowercase: %.2f uppercase: %.2f\n", ((float)low/(low+high))*100, ((float)high/(low+high))*100);
	}

	return 0;
}