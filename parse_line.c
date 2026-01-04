#include "shell.h"
/**
* parse_line - splits input into tokens (commands and arguments)
* @line: buffer containing raw input; modified in place
*
* Return: array of strings (command + arguments + NULL terminator)
*/
char **parse_line(char *line)
{
	int bufsize = 64, position = 0;
	char **args = malloc(bufsize * sizeof(char *));
	char *token;

	if (!args) /*handle allocation failure*/
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\n"); /*split line into tokens*/
	while (token != NULL)
	{
		args[position++] = token; /*assign token to args array*/
		if (position >= bufsize - 1) /* resize args array*/
		{
			bufsize += 64;
			args = realloc(args, bufsize * sizeof(char *));
			if (!args) /* handle realloc failure */
			{
				perror("realloc failed");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\n"); /*get next token*/
	}
	args[position] = NULL; /*null-terminate the array*/
	return (args); /*return the array of arguments*/
}
