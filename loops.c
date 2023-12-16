#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * @ s_loop - Shell LOOP reads stdin, parses and runs program.
 * handles both interactive and non-interactive mode
 * @ ags - agrguments
 * @ line - line of arguments to be parsed
*/
void s_loop(void)
{
    int status;
    char * line;
    char ** ags;
    
    do
    {
        printf("$");
        line = read_line();
        ags = split_line(line);
        status = execute(ags);
        free(line);
        free(ags);

    } while (status != 0);
    do{
        shell_no_inter();
    }while(status == -1);
}
