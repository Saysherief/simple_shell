#include "shell.h"

/**
 * sig_handler - handle signals
 * @sig: signal
 *
 * Return: nothing
 */
void sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		prompt();
		fflush(stdout);
	}
}
