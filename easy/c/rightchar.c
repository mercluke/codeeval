#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readWord(FILE* file, int del);

int main(int argc, char **argv)
{
	FILE* fp;
	char c;
	char *str;
	int len;
	int pos;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		fseek(fp, -1, SEEK_CUR);
		str = readWord(fp, ',');
		fscanf(fp, "%c\n", &c);
		len = strlen(str);
		pos = -1;

		while(len > 0)
		{
			if(str[--len] == c)
			{
				pos = len;
				break;
			}
		}
		printf("%i\n",pos);
		free(str);
	}

	return 0;
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