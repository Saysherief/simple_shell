#include "shell.h"

/**
 * prompt - prints the commmand prompt($) and waits for input from user
 *
 * Return: nothing
 */
void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
