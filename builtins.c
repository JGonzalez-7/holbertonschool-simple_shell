#include "shell.h"

/**
 * builtin_exit - Exits the shell
 * @args: Array of arguments (unused)
 * @last_status: Last command status to use when no argument is provided
 *
 * Description: Implements the exit built-in command.
 * Exits the shell with status 0.
 *
 * Return: Does not return (exits the program)
 */
void builtin_exit(char **args, int last_status)
{
	int status = last_status;

	if (args[1] != NULL)
		status = atoi(args[1]);

	exit(status);
}

/**
 * builtin_env - Prints the current environment
 * @args: Array of arguments (unused)
 *
 * Description: Implements the env built-in command.
 * Prints all environment variables to stdout.
 *
 * Return: 0 to indicate success
 */
int builtin_env(char **args)
{
	int i;

	(void)args;
	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
