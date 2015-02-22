#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fp;
	int age;
	
	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		fseek(fp, -1, SEEK_CUR);

		fscanf(fp, "%i\n", &age);

		if(age < 0)
		{
			printf("This program is for humans\n");
		}
		else if(age < 3)
		{
			printf("Still in Mama's arms\n");
		}
		else if(age < 5)
		{
			printf("Preschool Maniac\n");
		}
		else if(age < 12)
		{
			printf("Elementary school\n");
		}
		else if(age < 15)
		{
			printf("Middle school\n");
		}
		else if(age < 19)
		{
			printf("High school\n");
		}
		else if(age < 23)
		{
			printf("College\n");
		}
		else if(age < 66)
		{
			printf("Working for the man\n");
		}
		else if(age < 101)
		{
			printf("The Golden Years\n");
		}
		else
		{
			printf("This program is for humans\n");
		}

	}
	return 0;
}