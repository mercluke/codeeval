#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	FILE* fp;
    int n, p1, p2, ii, jj;

    fp = fopen(argv[1], "r");

    while(fscanf(fp, "%i,%i,%i\n", &n, &p1, &p2)  == 3)
    {
        p1 = n >> (p1-1);
        p1 &= 1; 
        p2 = n >> (p2-1);
        p2 &= 1; 
        printf("%s\n", (p1 == p2) ? "true" : "false");
    }
	return 0;
}