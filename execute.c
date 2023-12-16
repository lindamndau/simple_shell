#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * @ execute - executing fuction for shell
 * Return - args
 * 
*/
int execute(char **argv)
{
    int j;
    if(argv[1] == NULL)
    {
        return 1;
    }
    for(j = 0; j < num_builtins(); j++)
    {
        char b = strcmp(argv[1], bc_str[j]);
        if(b == 0)
        {
            return (*bc_func[j]) (argv);
        }
    }
    return launch(argv);
}
