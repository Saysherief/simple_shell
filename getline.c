#include "shell.h"

/**
 * _getline - a function that reads any command on shell prompt
 * @lineptr: pointer to the buffer
 * @n: pointer to the size of the buffer
 * @stream: pointer to the input stream to read from
 * Return: size of buffer
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	return (getline(lineptr, n, stream));
}

/**
 * my_exit - handles exit
 * @argv: pointer to pointer
 * @av: pointer to pointer
 * @line: pointer
 *
 * Return: nothing
 */
void my_exit(char **argv, char **av, char *line)
{
	int status;

	if (strcmp(av[0], "exit") == 0)
	{
		if (av[1])
		{
			status = atoi(av[1]);
			if (status <= 0)
			{
				printf("after\n");
				fprintf(stderr, "%s: 1: exit: Illegal number: %s\n", argv[0], av[1]);
				_free(line, av);
				exit(2);
			}
			_free(line, av);
			exit(status);
		}
	}
}
