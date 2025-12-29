#include "shell.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * handle_builtin - checks and executes built-in commands
 *
 * Description:
 * This function checks if the given command is a built-in command
 * (like 'cd', 'exit', or 'env') and executes it if so.
 * If the command is not a built-in, it returns 0 to indicate
 * that the caller should handle it as an external command.
 *
 * @args: array of strings containing the command and its arguments.
 *
 * Return: 1 if the command was a built-in and was handled,
 *         0 if the command is not a built-in and needs further
*	processing.
 */
int handle_builtin(char **args)
{
	if (args == NULL || args[0] == NULL)
		return (0); /* no command entered */
	if (strcmp(args[0], "exit") == 0)
	{
		exit(0); /* exit the shell */
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			fprintf(stderr, "cd: expected argument\n");
		}
		else
		{
			if (chdir(args[1]) != 0)
				perror("cd failed");
		}
		return (1); /* handled */
	}
	return (0); /* not a builtin, caller should exec */
}
