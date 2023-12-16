#ifndef MAIN_H
#define MAIN_H

/******************* Header files ****************************/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
/******************* Macros ***********************************/
#define rl_buffsize 1024
#define tok_buffsize 64
#define tok_delimit " \t\r\n\a\""
#define SIZE 3
#define FSIZE 3

/******************* Non- interactive shell mode ***************/
char * read_s(void);
void shell_no_inter(void);

/******************* Shell functions **************************/
char * read_line();
char **split_line(char *line);
char * read_line();
void s_loop();
int launch(char ** argsv);
int execute(char **argv);

/******************** Builtin commands ***********************/
int num_builtins();
char * bc_str[SIZE];
int (*bc_func[FSIZE])(char **);
void printenv(void);
int s_exit(char **argv);
#endif 
