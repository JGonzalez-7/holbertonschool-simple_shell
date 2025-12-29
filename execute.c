#include  "shell.h"

/**
* executed_command - Executes a command using fork + execve
*
*Description:
* create a child process with fork().
* In the child process, use execve() to execute the command.
* If execve() fails, print an error message.
* The parents waits for the child to finish using waitpid().
* @args: array of strings containing the command and its arguments.
*Rerurn: 0 on success, -1 on failure
*/
int execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork(); /* Create a child process */

	if (pid == -1) /* Error creating child process */
	{
		perror("fork failed"); /* Print error if  fork fails */
		return (-1);
	}
	if (pid == 0) /*child process */
	{
		if (execve(args[0], args, environ) == -1) /* Execute the command */
		{
			perror("execve failed"); /*Print error if commadn not found */
		}
		exit(EXIT_FAILURE); /* Exit child if execve fails */
	}
	else /* Parent process*/
	{
		waitpid(pid, &status, 0); /* wait for child to finish */
	}
	return (1); /* Return success */
}
