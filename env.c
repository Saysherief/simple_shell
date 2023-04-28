#include "shell.h"

void _env(void);

/**
 * _env - handles builtin env
 *
 * Return: nothing
 */
void _env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

char *builtin_command[] = {
	"env"
};

/**
 * builtin_fun[] - pointer to builtin functions
 * @builtin_fun: pointer to a function
 * Return: void
 */
void (*builtin_fun[])(void) = {
	&_env
};
