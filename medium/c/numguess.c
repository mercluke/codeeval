#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* readWord(FILE* file, int del);

int main(int argc, char **argv)
{
	FILE *fp;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		int min = 0, max;
		char *hint;

		fseek(fp, -1, SEEK_CUR);

		fscanf(fp, "%i ", &max);

		while((hint = readWord(fp, ' '))[0] != 'Y')
		{
			int guess = min+ceil((max-min)/(float)2);

			if(hint[0] == 'L')
			{
				max = guess-1;
			}
			else if(hint[0] == 'H')
			{
				min = guess+1;
			}

			free(hint);
		}

		int guess = min+ceil((max-min)/(float)2);
		printf("%i\n", guess);
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