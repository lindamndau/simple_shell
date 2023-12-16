#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * @ Discription - forks and evecvp the process
 * @ pd - process id
 * 
*/
pid_t wpid;
int launch(char ** argsv)
{
    int status;
    pid_t pd;
    pd = fork();
    if(pd == 0)
    {
        if(execvp(argsv[0], argsv) == -1)
        {
            perror("hsh");
        }
        exit(EXIT_FAILURE);
    }

    else if(pd < 0)
    {
        perror("hsh");
    }
    do
    {
        wpid = waitpid(pd, &status, WUNTRACED);
    } 
    while (!WIFSIGNALED(status) && !WIFEXITED(status));
    return 1;   
}
