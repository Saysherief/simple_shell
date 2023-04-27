#include "shell.h"

/**
 * prompt - prints the commmand prompt($) and waits for input from user
 *
 * Return: nothing
 */
void prompt(void)
{
	int mode;

	mode = isatty(STDIN_FILENO);
	if (mode == 1)
		write(STDOUT_FILENO, "simple_shell$ ", 14);
	fflush(stdout);
}
