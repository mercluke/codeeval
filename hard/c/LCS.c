#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printlcs(char **b, char *x, int ii, int jj);
char* readWord(FILE* file, int del);
void buildlcs(FILE *fp);


int main(int argc, char **argv)
{
	FILE *fp;
	int c;

	fp = fopen(argv[1], "r");

	while((c =fgetc(fp)) != EOF)
	{
		if(c != '\n')
		{
			fseek(fp, -1, SEEK_CUR);
			buildlcs(fp);
		}
	}	

	return 0;

}

void buildlcs(FILE *fp)
{
	int m, n, ii, jj;
	char *x, *y;
	char **b;
	int **c;

	x = readWord(fp, ';');
	y = readWord(fp, '\n');
	m = strlen(x)+1;
	n = strlen(y)+1;
	b = malloc(sizeof(char*) * m);
	c = malloc(sizeof(int*) * m);



	for(ii = 0; ii < m; ii++)
	{
		b[ii] = malloc(sizeof(char) * n);
		c[ii] = malloc(sizeof(int) * n);
		b[ii][0] = 0;
		c[ii][0] = 0;
	}
	for(jj = 0; jj < n; jj++)
	{
		b[0][jj] = 0;
		c[0][jj] = 0;
	}

	for(ii = 1; ii < m; ii++)
	{
		for(jj = 1; jj < n; jj++)
		{
			if(x[ii-1] == y[jj-1])
			{
				c[ii][jj] = c[ii-1][jj-1]+1;
				b[ii][jj] = '\\';
			}
			else if(c[ii-1][jj] <= c[ii][jj-1])
			{
				c[ii][jj] = c[ii][jj-1];
				b[ii][jj] = '-';
			}
			else
			{
				c[ii][jj] = c[ii-1][jj];
				b[ii][jj] = '|';
			}

		}
		
	}

	printlcs(b,x,m-1,n-1);
	putchar('\n');

	return;
}

void printlcs(char **b, char *x, int ii, int jj)
{
	if(ii == 0 || jj == 0)
	{
		return;
	}
	if (b[ii][jj] == '\\')
	{
		printlcs(b,x,ii-1,jj-1);
		putchar(x[ii-1]);
	}
	else if(b[ii][jj] == '|')
	{
		printlcs(b,x,ii-1,jj);
	}
	else if(b[ii][jj])
	{
		printlcs(b,x,ii,jj-1);
	}
}

char* readWord(FILE* file, int del)
{
    /*starter length for line buffer size*/
    int lineBufferLength = 20;
    /*current line position*/
    int count = 0;
    /*create some space for the linebuffer to store text until eol*/
    char* lineBuffer = (char*)malloc(sizeof(char)*lineBufferLength);
    /*read first character on line*/
    int currCh = fgetc(file);

    /*until either end of line or end of file*/
    while(currCh != '\n' && currCh != EOF && currCh != del)
    {
        if(currCh != '\r') /*windows blahblahblah*/
        {
            /*double size of line buffer if too short...*/
            if(count == lineBufferLength-1)
            {
                lineBufferLength *= 2;
                lineBuffer = realloc(lineBuffer, lineBufferLength);
            }
            
            /*need to typecast to char because we are
            storing as int in order to check for eof*/
            lineBuffer[count] = (char)currCh;
            count++;
        }
        /*move to next character*/
       currCh = fgetc(file);
    }   

    /*terminate the string*/
    lineBuffer[count] = '\0';
    
    /*free any extra space at the end of the string*/
    lineBuffer = realloc(lineBuffer, (sizeof(char)*++count));
    
    return lineBuffer;
}