#include <stdio.h>
#include <stdlib.h>

char* readLine(FILE* file, int *len);

int main(int argc, char **argv)
{
	FILE *fp;
	int c;
	fp = fopen(argv[1], "r");

	while((c = fgetc(fp)) != EOF)
	{
		int count = 0;
		char strStart[56];

		fseek(fp, -1, SEEK_CUR);

		while(count < 40 && (c = fgetc(fp)) != '\n' && c != EOF)
		{
			strStart[count] = c;
			count++;
		}

		strStart[count] = '\0';

		if(count == 40)
		{
			char *rest;
			int restcount;

			rest = readLine(fp, &restcount);

			//greater than 55 chars
			if(restcount > 15)
			{
				while(count >= 0)
				{
					if(strStart[count--] == ' ')
					{
						break;
					}
				}

				if(count > 0)
				{
					strStart[count+1] = 0;
				}
				printf("%s%s", strStart, "... <Read More>");
			}
			//less than 55 chars
			else
			{
				printf("%s%s", strStart, rest);
			}
			free(rest);
		}
		//less than 40 chars
		else
		{
			printf("%s", strStart);
		}
		putchar('\n');

	}

	fclose(fp);

	return 0;
}


/*read a single line from file*/
char* readLine(FILE* file, int *len)
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
            lineBuffer[count] = (char)currCh;
            count++;
        }
        /*move to next character*/
       currCh = fgetc(file);
    }   

    /*terminate the string*/
    lineBuffer[count] = '\0';
    *len = count;
    
    /*free any extra space at the end of the string*/
    lineBuffer = realloc(lineBuffer, (sizeof(char)*++count));
    
    return lineBuffer;
}