#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv)
{
	FILE* fp;
	char* line;
    int x, n, tot, i = 1;

	fp = fopen(argv[1], "r");
	
	while(fgetc(fp) != EOF)
    {
        fseek(fp, -1, SEEK_CUR);
        fscanf(fp, "%i, %i\n", &x, &n);
        tot = n;

        while(tot < x)
        {
            tot+=n;
        }
        printf("%i\n", tot);
    }

	return 0;
}