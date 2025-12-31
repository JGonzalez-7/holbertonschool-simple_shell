#include "shell.h"

/**
 * print_error - Prints error message for command not found
 * @command: The command that was not found
 *
 * Description: Prints an error message to stderr when a command
 * is not found in PATH or as an absolute path.
 */
void print_error(char *command)
{
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, ": command not found\n", 20);
}
