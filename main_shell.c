#include "shell.h"

/**
 * main - Entry point of the simple shell program
 *
 * Description:
 * This function runs the main loop of the shell. It continuously
 * displays a prompt, reads user input from standard input, parses
 * the command line into arguments, checks for built-in commands,
 * and executes external commands using fork and execve.
 * The loop only stops when an end-of-file condition (Ctrl + D)
 * is encountered.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *line;
	char **args;

	while (1)
	{
		print_prompt();
		line = read_line();

		if (line == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		args = parse_line(line);
		if (args && args[0])
		{
			if (!handle_builtin(args) == 0)
				execute_command(args);
		}

		free(line);
		free(args);
	}
	return (0);
}
