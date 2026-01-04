#include "shell.h"
/**
 * read_line - reads a line of input from the user
 *
 *Description:
 *Uses getline() to read a line of input from standard input (stdin).
 *hamdles EOF (Crtl+D) by returning NULL.
 *Return: pointer to the read line, or NULL on EOF or error
 */
char *read_line(void)
{
	char *line = NULL; /* Buffer to hold the input line */
	size_t bufsize = 0; /* Size of the buffer managed by getline */
	ssize_t nread; /* Number of characters read by getline */

	nread = getline(&line, &bufsize, stdin); /* Read input line */

	if (nread == -1) /* If EOF (Crt+D) or error */
	{
		free(line); /* Free the buffer (allocated memory) */
		return (NULL); /* Return NULL on EOF or error */
	}
	return (line); /* Return the read line */
}
