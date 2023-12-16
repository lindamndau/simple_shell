#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 3
#define FSIZE 3

/**
 * @ Discription - All builtin commands functions
 * 
 * 
*/
int cd(char **args);
int help(char **args);
int s_exit(char **argv);
void printenv(void);
/**
 * @ bc_str - List of all builtin commands
*/
char *bc_str[SIZE] =
{
    "cd", "help", "exit"
};

int (*bc_func[FSIZE])(char **) = {
    &cd,
    &help,
    &s_exit,
};
/**
 * @ num_builtins - 
*/
int num_builtins()
{
    return sizeof(bc_func)/ sizeof(char *);
}
/**
 * @Discription - Help, list of all functions
 * Prints - all functions in shell
*/
int help(char **args)
{
    	int i;
    	printf("%s\n", args[1]);
    	printf("Type program names and arguments, and hit enter.\n");
    	printf("The following are built in commands:\n");
    	for(i = 0; i < num_builtins(); i++)
    	{
        	printf("  %s\n", bc_str[i]);
    	}
	return 1;
}

/**
 * @ cd -  change of directory.
 * Returns 0 success (-1) error
*/
int cd(char **argv)
{
    char *lastdir = NULL;
    const char *path = argv[1];
    if(argv[1] == NULL)
    {
        char *home_dir = getenv("HOME");
        if (home_dir != NULL)
        {
            if (chdir(home_dir) != 0) 
            {
                perror("cd");
                return 1;
            }
        }
        return 1;
    }
    else 
    {
        fprintf(stderr, "Home directory not found\n");
        return 1;
    }
    if(chdir(path) != -1)
    {
        if (!strcmp(argv[1], "-")) 
        {
            lastdir = getenv("OLDPWD");
            if (lastdir == NULL || chdir(lastdir) != 0)
            {
                fprintf(stderr, "No previous directory\n");
                return 1;
            }
            printf("%s\n", lastdir);
            return 1;
            if (*lastdir == '\0')
            {
                fprintf(stderr, "no previous directory\n");
                return 1;
            }
            perror("cd");
        }
         return 1;
    }
    return 1;
}
/**
 * @s_exit- Shell exit handler
 * Returns 0 
 * 
*/
int s_exit(char **argv)
{
	if(strcmp(argv[1], "exit") == 0)
	{
    		return 0;
	}
	return 1;
}
/**
 * @printenv - prints enviroment(pwd)
*/
void printenv(void)
{
    char ** env;
    extern char **environ;
    env = environ;
    for(; *env; env++)
    {
        printf("%s\n", *env);
    }
}
