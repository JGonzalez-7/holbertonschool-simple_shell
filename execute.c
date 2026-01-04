#include "shell.h"

/**
 * execute_command - run a command
 * @args: argv
 * @program: shell name
 * @line_count: input line number
 * Return: exit status code
 */

int execute_command(char **args, char *program, int line_count)
{
	pid_t pid;
	int status;
	char *cmd_path = find_path(args[0]);

	if (!cmd_path)
		return (print_error(program, line_count, args[0], "not found"), 127);
	if (access(cmd_path, X_OK) != 0)
		return (print_error(program, line_count, args[0], "Permission denied"),
			free(cmd_path), 126);
	pid = fork();
	if (pid == -1)
		return (perror("fork failed"), free(cmd_path), 1);
	if (pid == 0)
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			if (errno == EACCES)
				exit(126);
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, &status, 0);
	free(cmd_path);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
