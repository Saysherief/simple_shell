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
	int status, mode = isatty(STDIN_FILENO);
	pid_t p_pid = getpid(), pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		child_process(av, argv, mode, p_pid);
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			exit(EXIT_FAILURE); }
	}
}

/**
 * child_process - the child process
 * @av: pointer to pointer
 * @argv: pointer to pointer
 * @mode: return of isatty
 * @p_pid: parent pid
 *
 * Return: nothing
 */
void child_process(char **av, char **argv, int mode, pid_t p_pid)
{
	int i, c_line;
	char *st_line, *error_msg, *not_found_msg;
	pid_t ch_pid;

	ch_pid = getpid();
	c_line = ch_pid - p_pid;
	if (access(av[0], X_OK) == -1)
	{
		if (mode != 1)
			error_msg = _strcat(argv[0], ": 1: ");
		else
		{
			st_line = _itoa(c_line);
			error_msg = _strcat(argv[0], ": ");
			error_msg = _strcat(error_msg, st_line);
			error_msg = _strcat(error_msg, ": ");
		}
		write(STDERR_FILENO, error_msg, _strlen(error_msg));
		write(STDERR_FILENO, av[0], _strlen(av[0]));
		not_found_msg = ": not found\n";
		write(STDERR_FILENO, not_found_msg, _strlen(not_found_msg));
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		exit(EXIT_FAILURE); }
	if (execve(av[0], av, NULL) == -1)
	{
		perror(argv[0]);
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		exit(EXIT_FAILURE); }
}
