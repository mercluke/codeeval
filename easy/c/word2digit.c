#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* readWord(FILE* file, int del);

int main(int argc, char **argv)
{
    FILE *fp;
    int c;

    fp = fopen(argv[1], "r");

    while(fgetc(fp) != EOF)
    {
        fseek(fp,-1,SEEK_CUR);

        char *num;

        while((num = readWord(fp, ';')))
        {
            if(!strcmp(num,"zero"))
            {
                putchar('0');
            }
            else if(!strcmp(num,"one"))
            {
                putchar('1');
            }
            else if(!strcmp(num,"two"))
            {
                putchar('2');
            }
            else if(!strcmp(num,"three"))
            {
                putchar('3');
            }
            else if(!strcmp(num,"four"))
            {
                putchar('4');
            }
            else if(!strcmp(num,"five"))
            {
                putchar('5');
            }
            else if(!strcmp(num,"six"))
            {
                putchar('6');
            }
            else if(!strcmp(num,"seven"))
            {
                putchar('7');
            }
            else if(!strcmp(num,"eight"))
            {
                putchar('8');
            }
            else if(!strcmp(num,"nine"))
            {
                putchar('9');
            }
        }
        putchar('\n');
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

    if(currCh == '\n' && count != 0)
    {
        fseek(file, -1, SEEK_CUR);
    }

    /*terminate the string*/
    lineBuffer[count] = '\0';
    
    /*free any extra space at the end of the string*/
    lineBuffer = realloc(lineBuffer, (sizeof(char)*++count));
    
    return (*lineBuffer) ? lineBuffer : NULL;
}