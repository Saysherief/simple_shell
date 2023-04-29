#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <stddef.h>
#include <signal.h>

#define MAX 1024
extern char **environ;

void prompt(void);
char **handle_args(char *lineptr);
void handle_EOF(ssize_t nread, char *line);
int exec_command(char **av, char **argv, char *line);
void child_process(char **av, char **argv, char *line, int mode, pid_t p_pid);
void sig_handler(int sig);
void _env(void);
void my_exit(char **argv, char **av, char *line);
void _free(char *line, char **av);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_itoa(int num);
void rev_string(char *s);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif /* SHELL_H */
