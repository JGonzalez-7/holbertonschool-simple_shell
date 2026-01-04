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
 * @argc: Argument count (unused)
 * @argv: Argument vector; argv[0] is used for error messages
 *
 * Return: Exit status of last executed command
 */

int main(int argc, char **argv)
{
	char *line;
	char **args;
	int interactive = isatty(STDIN_FILENO);
	int status = 0;
	int line_count = 0;
	char *program = argv[0];

	(void)argc;

	while (1)
	{
		if (interactive)
			print_prompt();
		line = read_line();

		if (line == NULL)
		{
			if (interactive)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

			args = parse_line(line);
			if (args && args[0])
			{
				line_count++;
				if (strcmp(args[0], "exit") == 0)
				{
					if (args[1] != NULL)
						status = atoi(args[1]);
					free(line);
					free(args);
					exit(status);
				}
				if (handle_builtin(args, &status) == 0)
					status = execute_command(args, program, line_count);
			}

			free(line);
			free(args);
		}
	return (status);
}
