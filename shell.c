#include "shell.h"
/**
 * main - simple UNIX command line interpreter
 * @argc: number of arguments supplied to the program, currently not used on 1
 * @argv: array of pointers to the strings passed as arguments
 * Return: always 0 (success)
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *line, **av;
	int i;
	size_t size = 0;
	ssize_t nread;

	while (1)
	{
		prompt();
		line = NULL;
		nread = getline(&line, &size, stdin);
		handle_EOF(nread);
		av = handle_args(line);
		exec_command(av, argv);
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(line);
	}
	return (0);
}

/**
 * handle_args - function that will handle command-line args
 * @lineptr: points to the line read by getline
 *
 * Return: pointer  to a pointer
 */
char **handle_args(char *lineptr)
{
	char *token, **args = NULL;
	int i, n;

	token = strtok(lineptr, " \n");

	args = malloc(sizeof(char *) * (MAX + 1));
	if (!args)
		return (NULL);

	n = 0;
	while (token && n < MAX)
	{
		args[n] = malloc(_strlen(token) + 1);
		if (!args[n])
		{
			for (i = 0; i < n; i++)
				free(args[i]);
			free(args);
			return (NULL);
		}
		_strcpy(args[n], token);
		n++;

		token = strtok(NULL, " \n");
	}
	args[n] = NULL;

	return (args);
}

/**
 * handle_EOF - handles EOF
 * @nread: the return of getline
 *
 * Return: nothing
 */
void handle_EOF(ssize_t nread)
{
	int mode = isatty(STDIN_FILENO);

	if (nread == -1)
	{
		if (EOF && mode == 1)
			write(1, "\n", 2);
		exit(EXIT_FAILURE);
	}
}

/**
 * exec_command - execute the given command
 * @av: pointer to a pointer
 * @argv: command-line argument
 *
 * Return: nothing
 */
void exec_command(char **av, char **argv)
{
	int status, i;
	pid_t pid = fork();

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
			for (i = 0; av[i]; i++)
				free(av[i]);
			free(av);
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
}
