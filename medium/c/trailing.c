#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readWord(FILE* file, int del);

int main(int argc, char **argv)
{
	FILE *fp;

	int c;

	fp = fopen(argv[1], "r");

	while((c = fgetc(fp)) != EOF)
	{
		char *str, *trail;
		int strLen, trailLen;

		int match = 0;

		if(c != '\n')
		{

			fseek(fp, -1, SEEK_CUR);

			str = readWord(fp, ',');
			trail = readWord(fp, '\n');

			strLen = strlen(str)-1;
			trailLen = strlen(trail)-1;

			if(strLen >= trailLen)
			{
				match = 1;

				while(trailLen >= 0)
				{
					if(str[strLen] != trail[trailLen])
					{
						match = 0;
						break;
					}
					trailLen--;
					strLen--;
				}
			}

			printf("%i\n", match);
			free(str);
			free(trail);
		}	
	}

	fclose(fp);
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