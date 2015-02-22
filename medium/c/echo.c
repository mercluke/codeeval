#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
FILE *fp;
int c;
fp = fopen(argv[1], "r");

		printf("\n\n\n\n\n\ndongs\n\n\n\n\n\n\n\n");

while((c = fgetc(fp)) != EOF){
	putchar(c);
}

		printf("\n\n\n\n\n\ndongs\n\n\n\n\n\n\n\n");

return 0;	
}