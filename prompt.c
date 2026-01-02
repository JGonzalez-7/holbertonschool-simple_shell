#include "shell.h"

/**
* print_prompt - prints the shell prompt
* Description:
* writes simple "$" prompt to standard output.
*/
void print_prompt(void)
{
	write(STDOUT_FILENO, "($) ", 4); /*Print "($) " to the terminal */
}
