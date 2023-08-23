#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stddef.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

/*func builtin*/
int _cd(const char *path);

/*func to control strings*/
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char **split_string(char *str, const char *delim);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);

/*memory management*/
void freeav(char **av);
void exitfree(char **av);

/*init*/
void interactive(void);
void _EOF(char *buf);
void sig_hd(int sig_n);
void sh_exit(char **av);

/*execution control*/
void print_env(char **environ);
char **_getPATH(char **environ);
void execute(char **av, char *name, char **environ, int cy);
void sup_process(char **av, char *name, char **environ, int cy);
void msg_errors(char *name, int cy, char **av);

#endif
