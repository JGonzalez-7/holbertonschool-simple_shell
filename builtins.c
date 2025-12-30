#include "shell.h"

/**
 * builtin_exit - Exits the shell
 * @args: Array of arguments (unused)
 *
 * Description: Implements the exit built-in command.
 * Exits the shell with status 0.
 *
 * Return: Does not return (exits the program)
 */
int builtin_exit(char **args)
{
	(void)args;
	exit(0);
}

/**
 * builtin_env - Prints the current environment
 * @args: Array of arguments (unused)
 *
 * Description: Implements the env built-in command.
 * Prints all environment variables to stdout.
 *
 * Return: 1 to continue the shell loop
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
	return (1);
}
