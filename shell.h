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

/**
 * struct lpath - linked list continning $PATH directories
 * @dir: directory in path
 * @np: pointer to next node
 */
typedef struct lpath
{
	char *dir;
	struct lpath *np;
} lpath;

/**
 * struct shbuildin - pointer to function with buildin shell command
 * @ncmd: buildin command
 * @func: function execute the buildin shell command
 */
typedef struct shbuildin
{
	char *ncmd;
	void (*func)(char **);
} shbuildin;

/*handles the end of file*/
void _EOF(char *buf);

/*linked list manipulate*/
lpath *add_node_end(lpath **head, char *str);
lpath *lk_path(char *path);
void free_list(lpath *head);

/*func to print strings*/
int _putchar(char c);
void print(char *str);

/*func to control strings*/
unsigned int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *name, char *sep, char *value);
char **split_string(char *str, const char *delim);
int _atoi(char *s);

/*memory management*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*environment functions*/
void env(char **av);
char *_getenv(const char *name);
void _setenv(char **av);
void _unsetenv(char **av);
void sh_exit(char **av);
char *_which(char *filename, lpath *head);

/*execution control*/
void execute(char **av);
void(*cmd_check(char **av))(char **av);
void freeav(char **av);
void interactive(void);

/*signal handler*/
void sig_hd(int sig_n);

#endif
