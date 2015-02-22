#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int sum = 0, n;
    FILE* fp;

    fp = fopen(argv[1], "r");
    while(fgetc(fp) != EOF)
    {
        fseek(fp, -1, SEEK_CUR);

        fscanf(fp, "%i\n", &n);
        sum+=n;
    }
    printf("%i\n", sum);
    
	return 0;
}