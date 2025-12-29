#include "shell.h"
/**
* parse_line - splits input into tokens
*
* Description:
* Uses strtok() to plist the line into words.
* Since commands are only one word (no  arguments),
* we only need to split by spaces.
*
* Return: array of strings (command + NULL terminator)
*/
char **parse_line(char *line)
{
	char **args = malloc(2 * sizeof(char *));
	char *token;

	if (!args) /* Check for malloc failure */
	{
		perror("malloc failed"); /* Print error if allocation fails */
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\n"); /* split input by spaces, tabs, and newlines */
	args[0] = token; /* First token is the command */
	args[1] = NULL; /* Null-terminate the array */

	return (args); /* Return the array of arguments */
}
