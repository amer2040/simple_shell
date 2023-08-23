#include "shell.h"

/**
 * print_env - function that prints all enviromental variables.
 *
 * @environ: pointer to enviromental variables.
 *
 * Return: Nothing.
 */
void print_env(char **environ)
{
	size_t x = 0;
	size_t len = 0;

	while (environ[x])
	{
		len = _strlen(environ[x]);
		write(STDOUT_FILENO, environ[x], len);
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}

/**
 * msg_errors - function that prints message of errors.
 *
 * @name: The name of the shell.
 * @cy: Number of cicles.
 * @av: pointer to tokenized command.
 *
 * Return: Nothing.
 */
void msg_errors(char *name, int cy, char **av)
{
	char c;

	c = cy + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, av[0], _strlen(av[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}

/**
 * _getPATH - function to gets the full value from
 * enviromental variable PATH.
 *
 * @environ: pointer to enviromental variables.
 *
 * Return: All tokenized pathnames for commands.
 */
char **_getPATH(char **environ)
{
	char *pathvalue = NULL;
	char **pathnames = NULL;
	unsigned int x = 0;

	pathvalue = strtok(environ[x], "=");
	while (environ[x])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathnames = split_string(pathvalue, ":");
			return (pathnames);
		}
		x++;
		pathvalue = strtok(environ[x], "=");
	}
	return (NULL);
}

