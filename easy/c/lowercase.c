#include <stdio.h>
#include <stdlib.h>

char* readLine(FILE* file);

int main(int argc, char** argv)
{
	FILE* fp;
	char* line;

	fp = fopen(argv[1], "r");
	
	for(line = readLine(fp);line;line = readLine(fp))
	{
		printf("%s\n", line);
	}
	return 0;
}

/*read a single line from file*/
char* readLine(FILE* file)
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
    while(currCh != '\n' && currCh != EOF)
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
            lineBuffer[count] = (currCh >= 'A' && currCh <= 'Z') ? (char)(currCh+32) : (char)currCh;
            count++;
        }
        /*move to next character*/
       currCh = fgetc(file);
    }   

    /*terminate the string*/
    lineBuffer[count] = '\0';
    
    /*free any extra space at the end of the string*/
    lineBuffer = realloc(lineBuffer, (sizeof(char)*++count));
    
    return (*lineBuffer) ? lineBuffer : NULL;
}