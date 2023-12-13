#ifndef MAIN_H
#define MAIN_H

/*lib used*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/*functions*/

char **tokenize_input(char *userInput_buf);
int check_spaces_tabs(char *str);
int command_exists(char **args);
int execute_command(char **args, char *userInput_buf);
int execute_forked_command(char **args, char *userInput_buf);
int handle_builtins(char **args, char *userInput_buf, int exit_nm);
int validate_command(char **args, char *userInput_buf, int exit_nm);
ssize_t read_user_input(char **userInput_buf, size_t *buff_size);
void handle_sig(int sig);
void free_args(char **args);

char *_sprintf(char *str, char *delim, char *src);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

#endif
