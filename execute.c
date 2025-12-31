#include "shell.h"

/**
 * execute_command - Executes a command using fork + execve
 *
 * Description:
 * Finds the command path using find_path().
 * If command not found, prints error and returns without forking.
 * Creates a child process with fork().
 * In the child process, uses execve() to execute the command.
 * The parent waits for the child to finish using waitpid().
 *
 * @args: array of strings containing the command and its arguments.
 *
 * Return: 1 on success to continue shell loop
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;
	char *cmd_path;

	cmd_path = find_path(args[0]);
	if (!cmd_path)
	{
		print_error(args[0]);
		return (1);
	}

	pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
		free(cmd_path);
		return (1);
	}

	if (pid == 0)
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			perror(args[0]);
			free(cmd_path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	free(cmd_path);
	return (1);
}
