#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * @ Discription - parses lines into commands
 * 
 * 
*/

char **split_line(char *line)
{
    int buffsize = tok_buffsize, position = 0;
    char * token, **tokens = malloc(buffsize * sizeof(char*));
    if(!tokens)
    {
        fprintf(stderr, "allocation error");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, tok_delimit);
    while(token != NULL)
    {
        tokens[position] = token;
        position++;
    
        if(position >= buffsize)
        {
            buffsize += tok_buffsize;
            tokens = realloc(tokens, buffsize * sizeof(char));
        
            if (!tokens) 
            {
            	fprintf(stderr, "lsh: allocation error\n");
            	exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, tok_delimit);
    }
    tokens[position] = NULL;
    return tokens;

}
