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
#include <limits.h>
#include <errno.h>

extern char **environ;
char *chk_equal(char *str);
int comp(char *varname, char *dirname);

/*start prompt*/
char *_getline(void);

/*func to print strings*/
int _putchar(char c);
void print(char *str);

/*func to control strings*/
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char **tokinizer(char *str, const char *delim);

/*control PATH*/
char **_findpath(char **environ);
char *path_args(char **parse, char **tokens);

/*Func Memory*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*environment functions*/
char *_getenv(char **environ, char *dirname);

/*execution control*/
int execute(char **av);
void(*cmd_check(char **av))(char **av);

/*signal handler*/
void sig_hd(int sig_n);

#endif
