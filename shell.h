#ifndef MAIN_H
#define MAIN_H

/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/* Environment */
extern char **environ;

/* Prompt */
void print_prompt(void);

/* Input */
char *read_line(void);

/* Parsing */
char **parse_line(char *line);

/* Execution */
int execute_command(char **args);

/* handle */
extern char **environ;

/* PATH */
char *find_path(char *command);

/* Builtins */
int handle_builtin(char **args);
int builtin_exit(char **args);
int builtin_env(char **args);

/* Errors */
void print_error(char *command);

#endif
