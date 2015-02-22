#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readWord(FILE* file, int del, int *eol, int *len);

int main(int argc, char **argv)
{
	FILE *fp;
	int c;

	fp = fopen(argv[1], "r");

	while((c =fgetc(fp)) != EOF)
	{
		int len = 0;
		int currlen;
		int eol = 0;
		char *longword = NULL;

		if(c != '\n')
		{
			char* currWord;
			fseek(fp, -1, SEEK_CUR);

			while((currWord  = readWord(fp, ' ', &eol, &currlen)))
			{
				if(currlen > len)
				{
					len = currlen;
					longword = currWord;
				}
				if(eol)
				{
					break;
				}
			}
			printf("%s\n", longword);
		}
	}
	return 0;
}

char* readWord(FILE* file, int del, int *eol, int *len)
{
    /*starter length for line buffer size*/
    int lineBufferLength = 32;
    /*current line position*/
    int count = 0;
    /*create some space for the linebuffer to store text until eol*/
    char* lineBuffer = (char*)malloc(sizeof(char) * lineBufferLength);
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
            lineBuffer[count++] = (char)currCh;
        }
        /*move to next character*/
       currCh = fgetc(file);
    }
    if(currCh == '\n' || currCh == EOF)
    {
    	*eol = 1;
    }

    /*terminate the string*/
    lineBuffer[count] = '\0';
    
    
    *len = count;

    return (*lineBuffer) ? lineBuffer : NULL;
}