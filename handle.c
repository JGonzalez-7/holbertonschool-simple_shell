#include "shell.h"

/**
 * handle_builtin - Checks and executes built-in commands
 * @args: Array of strings containing the command and its arguments
 *
 * Description: Checks if the given command is a built-in (exit, env)
 * and executes it. Returns 0 if not a built-in.
 *
 * Return: 1 if handled as built-in, 0 if not a built-in
 */
int handle_builtin(char **args)
{
	if (args == NULL || args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
		return (builtin_exit(args));

	if (strcmp(args[0], "env") == 0)
		return (builtin_env(args));

	return (0);
}
