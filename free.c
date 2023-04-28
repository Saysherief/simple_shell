#include "shell.h"

/**
 * _free - free memory
 * @line: pointer
 * @av: pointer to pointer
 *
 * Return: nothing
 */
void _free(char *line, char **av)
{
	int i;

	if (line)
		free(line);
	if (av)
	{
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
	}
}
