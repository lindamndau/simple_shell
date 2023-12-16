#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include "main.h"
/**
 * @ Discription - reads line by getting characters as input
*/
char * read_line()
{
    int buffsize = rl_buffsize;
    char * buffer = malloc(sizeof(char) * buffsize);
    int position = 0;
    int c;
    if(!buffer)
    {
        fprintf(stderr,"allocation error");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        c = getchar();
        if(c == EOF || c == '\n')
        {
            buffer[position] = '\n';
            return buffer;
        }
        else
        {
            buffer[position] = c;
        }
        position++;
    }
    if(position >= buffsize)
    {
        buffsize += rl_buffsize;
        buffer = realloc(buffer, buffsize);
        if(!buffer)
        {
            fprintf(stderr, "allocation error");
            exit(EXIT_FAILURE);
        }
    }
}
