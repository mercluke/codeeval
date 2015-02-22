#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv)
{
	FILE* fp;
	int* fib;
    int n, ii;

    fp = fopen(argv[1], "r");

    while(fgetc(fp) != EOF)
    {
        fseek(fp, -1, SEEK_CUR);
        fscanf(fp, "%i\n", &n);
        fib = malloc(sizeof(int) * n+1);
        fib[0] = 0;
        fib[1] = 1;

        for(ii = 2; ii <= n; ii++)
        {
            fib[ii] = fib[ii-1] + fib[ii-2];
        }

        printf("%i\n", fib[n]);
    }


	return 0;
}