#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if(argc == 2)
	{
		FILE* fp = fopen(argv[1], "rb");
		
		if(fp)
		{
			int X, Y, ii, jj;

			while(fgetc(fp) != EOF)
			{
				fseek(fp, -1,SEEK_CUR);
				fscanf(fp, "%i %i %i\n", &X, &Y, &jj);
				
				for(ii = 1; ii <= jj; ii++)
				{
					if(!(ii%X)){
						printf("F");
						if(!(ii%Y)){
							printf("B");
						}
					}
					else
					{
						if(!(ii%Y)){
							printf("B");
						}
						else{
							printf("%i", ii);
						}
					}
					printf(" ");	
				}
				printf("\n");
			}
		}
		else
		{
			printf("Error openeing file: %s\n", argv[1]);
		}
	}
	else
	{
		printf("Usage: %s <filname>\n", argv[0]);
	}

	return 0;
}