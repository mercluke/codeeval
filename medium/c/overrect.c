#include <stdio.h>
#include <stdlib.h>

int overlap(FILE *fp);

int main(int argc, char **argv)
{
	FILE *fp;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		fseek(fp, -1, SEEK_CUR);

		if(overlap(fp))
		{
			printf("True\n");
		}
		else
		{
			printf("False\n");
		}
	}
}

int overlap(FILE *fp)
{
	int aux, auy, alx, aly, bux, buy, blx, bly;
		

		fscanf(fp, "%i,%i,%i,%i,%i,%i,%i,%i\n", 
			&aux, &auy, &alx, &aly, &bux, &buy, &blx, &bly);

		//a wider
		if(alx-aux >= blx - bux)
		{
			//within width
			if((bux >= aux && bux <= alx) || (blx >= aux && blx <= alx))
			{
				//a taller
				if(auy-aly >= buy-bly)
				{
					if((buy <= auy && buy >= aly) || (bly <= auy && bly >= aly))
					{
						return 1;
					}
				}
				//b taller
				else
				{
					if((auy <= buy && auy >= bly) || (aly <= buy && aly >= bly))
					{
						return 1;
					}
				}
			}
		}
		//b wider
		else
		{
			//within width
			if((aux >= bux && aux <= blx) || (alx >= bux && alx <= blx))
			{
				//b taller
				if(buy-bly >= auy-aly)
				{
					if((auy <= buy && auy >= bly) || (aly <= buy && aly >= bly))
					{
						return 1;
					}
				}
				//a taller
				else
				{
					if((buy <= auy && buy >= aly) || (bly <= auy && bly >= aly))
					{
						return 1;
					}
				}
			}
		}

		return 0;
}