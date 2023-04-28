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

void prompt(void);
char **handle_args(char *lineptr);
void handle_EOF(ssize_t nread);
int exec_command(char **av, char **argv);
void child_process(char **av, char **argv, int mode, pid_t p_pid);
void sig_handler(int sig);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_itoa(int num);
void rev_string(char *s);

#endif /* SHELL_H */
