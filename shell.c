#include "shell.h"
/**
 * main - simple UNIX command line interpreter
 * @argc: number of arguments supplied to the program, currently not used on 1
 * @argv: array of pointers to the strings passed as arguments
 * Return: always 0 (success)
 */
int main(int argc __attribute__((unused)), char **argv)
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
		if (nread == -1) /*perror("getline");*/
			exit(EXIT_FAILURE);
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
				perror(argv[0]);
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
