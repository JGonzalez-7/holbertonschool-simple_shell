#include "shell.h"

/**
 * print_error - Prints formatted error message
 * @program: Name of the shell executable
 * @line_count: Line number of the current command
 * @command: The command that caused the error
 * @message: Error description
 *
 * Description: Prints errors using the format required by the project:
 * program: line: command: message
 */
void print_error(char *program, int line_count, char *command, char *message)
{
	char buffer[1024];
	int len;

	len = snprintf(buffer, sizeof(buffer), "%s: %d: %s: %s\n",
		       program, line_count, command, message);
	if (len > 0)
		write(STDERR_FILENO, buffer, len);
}
