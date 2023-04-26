#include "shell.h"

/**
 * main - simple UNIX command line interpreter
 *
 * Return: always 0 (success)
 */
int main(void)
{
	char *line, *av[2];
	int status;
	size_t size = 0;
	ssize_t nread;
	pid_t pid;

	while (1)
	{
		prompt();
		line = NULL;
		nread = getline(&line, &size, stdin);
		if (nread == -1)
		{
			/*perror("getline");*/
			exit(EXIT_FAILURE);
		}
		av[0] = strtok(line, " \n");
		av[1] = NULL;
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(av[0], av, NULL) == -1)
			{
				perror("./hsh");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (wait(&status) == -1)
			{
				perror("wait");
				exit(EXIT_FAILURE);
			}
		}

		free(line);
	}

	return (0);
}
