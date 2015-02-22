#include <stdio.h>
#include <stdlib.h>

int **matrix;
int ii;

void setCol(int col, int val);
void setRow(int row, int val);
int queryRow(int row);
int queryCol(int col);
char* readWord(FILE* file, int del);

int main(int argc, char** argv)
{
	FILE *fp;
	char *func;
	int arg1, arg2;

	matrix = malloc(sizeof(int*) * 256);

	for(ii = 0; ii < 256; ii++)
	{
		matrix[ii] = calloc(sizeof(int), 256);
	}

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		fseek(fp, -1, SEEK_CUR);

		func = readWord(fp, ' ');

		if(func[3] == 'C')
		{
			fscanf(fp, "%i %i\n", &arg1, &arg2);
			setCol(arg1, arg2);
		}
		else if(func[3] == 'R')
		{
			fscanf(fp, "%i %i\n", &arg1, &arg2);
			setRow(arg1, arg2);	
		}
		else if(func[5] == 'C')
		{
			fscanf(fp, "%i\n", &arg1);
			printf("%i\n", queryCol(arg1));
		}
		else
		{
			fscanf(fp, "%i\n", &arg1);
			printf("%i\n", queryRow(arg1));
		}
	}


	return 0;
}

void setCol(int col, int val)
{
	for(ii = 0; ii < 256; ii++)
	{
		matrix[col][ii] = val;
	}
}

void setRow(int row, int val)
{
	for(ii = 0; ii < 256; ii++)
	{
		matrix[ii][row] = val;
	}
}

int queryRow(int row)
{
	int ret = 0;

	for(ii = 0; ii < 256; ii++)
	{
		ret += matrix[ii][row];
	}

	return ret;
}

int queryCol(int col)
{
	int ret = 0;

	for(ii = 0; ii < 256; ii++)
	{
		ret += matrix[col][ii];
	}

	return ret;
}

char* readWord(FILE* file, int del)
{
    /*starter length for line buffer size*/
    int lineBufferLength = 32;
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