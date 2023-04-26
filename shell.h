#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

#define MAX 100

void prompt(void);
char **handle_args(char *lineptr);
void handle_EOF(ssize_t nread);
void exec_command(char **av, char **argv);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif /* SHELL_H */
