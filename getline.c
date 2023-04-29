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
