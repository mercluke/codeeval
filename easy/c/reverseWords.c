#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readLine(FILE* file, int* wordCount);

int main(int argc, char** argv)
{

		FILE* fp = fopen(argv[1], "rb");
		char** words;
		int ii;
		char* line;
		int wc;
		for(line = readLine(fp, &wc); line ; line = readLine(fp, &wc))
		{
			words = malloc(sizeof(char*) * wc+1);
			words[wc] = strtok(line, " ");
			for(ii = wc-1;ii >= 0; ii--)
			{
				words[ii] = strtok(NULL, " ");
			}

			for(ii = 0; ii <= wc; ii++)
			{
				printf("%s%s", words[ii], (ii != wc) ? " " : "\n");
			}
			free(line);
		}


	return 0;
}

char* readLine(FILE* file, int* wordCount)
{
    int lineBufferLength = 20;
    int count = 0;
    char* lineBuffer = (char*)malloc(sizeof(char)*lineBufferLength);
    int currCh = fgetc(file);

    (*wordCount) = 0;
    while(currCh != '\n' && currCh != EOF)
    {
        if(currCh != '\r')
        {
        	if(currCh == ' ') (*wordCount)++;
            if(count == lineBufferLength-1)
            {
                lineBufferLength *= 2;
                lineBuffer = realloc(lineBuffer, lineBufferLength);
            }
            lineBuffer[count] = (char)currCh;
            count++;
        }
       currCh = fgetc(file);
    }   
    lineBuffer[count] = '\0';
    lineBuffer = realloc(lineBuffer, (sizeof(char)*++count));
    
    return (*lineBuffer) ? lineBuffer : NULL;
}