#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * @read_s - reads line from stream.
 * @charac - character
 * Returns - pointer to read line 
*/
char * read_s(void)
{
    int buffsize = 1024;
    int j = 0;
    int charac;
    char * line = malloc(sizeof(char) * buffsize);
    if(line == NULL)
    {
        fprintf(stderr, "allocation failed");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        charac = getchar();
        if(charac == EOF)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
        else if(charac == '\n')
        {
            line[j] = '\0';
            return line;
        }
        else
        {
            line[j] = charac;
        }
        j++;
        if(j >= buffsize)
        {
            buffsize += buffsize;
            line = realloc(line, buffsize);
            if(line == NULL)
            {
                fprintf(stderr, "reallocation error");
                exit(EXIT_FAILURE);
            }
        }
    }
}
/**
 * @ shell_no_inter - non interactive  shell mode unix interpreter
 * 
*/
void shell_no_inter(void)
{
    int status;
    char * line;
    char ** ags;
    
    do{
        line = read_s();
	if(line == NULL)
	{
		continue;
	}
        ags = split_line(line);
	if(ags == NULL)
	{
		free(line);
		continue;
	}
        status = execute(ags);
        free(line);
        free(ags);
        if(status >= 0)
        {
            exit(status);
        }
    }while(status == -1);
}
