#include "shell.h"

/**
 * execute - the execute a commands.
 *
 * @av: pointer to tokenized command.
 * @name: The pointer to the name of shell.
 * @environ: The pointer to the enviromental variables.
 * @cy: The number of executed cycles.
 */
void execute(char **av, char *name, char **environ, int cy)
{
	char **pathname = NULL, *full_path = NULL;
	struct stat st;
	unsigned int x = 0;

	if (_strcmp(av[0], "env") != 0)
		print_env(environ);
	if (stat(av[0], &st) == 0)
	{
		if (execve(av[0], av, environ) < 0)
		{
			perror(name);
			exitfree(av);
		}
	}
	else
	{
		pathname = _getPATH(environ);
		while (pathname[x])
		{
			full_path = _strcat(pathname[x], av[0]);
			x++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, av, environ) < 0)
				{
					perror(name);
					freeav(pathname);
					exitfree(av);
				}
				return;
			}
		}
		msg_errors(name, cy, av);
		freeav(pathname);
	}
}

/**
 * freeav - frees the array of pointers av
 *
 *@av: array of pointers.
 */

void freeav(char **av)
{
	size_t x;

	if (av == NULL)
	{
		return;
	}

	for (x = 0; av[x]; x++)
		free(av[x]);

	if (av[x] == NULL)
	{
		free(av[x]);
	}

	free(av);
}

/**
 * exitfree - function that frees all the memory allocated and exit.
 *
 * @av: pointer to allocated command memory to free.
 */
void exitfree(char **av)
{
	size_t x = 0;

	if (av == NULL)
		return;

	while (av[x])
	{
		free(av[x]);
		x++;
	}

	if (av[x] == NULL)
		free(av[x]);
	free(av);
	exit(EXIT_FAILURE);
}

/**
 * sh_exit - exit from shell.
 *
 * @av: the array of words (commands arguments).
*/
void sh_exit(char **av)
{
	int x, n;

	if (av[1])
	{
		n = _atoi(av[1]);
		if (n <= -1)
			n = 2;
		freeav(av);
		exit(n);
	}
	for (x = 0; av[x]; x++)
		free(av[x]);
	free(av);
	exit(EXIT_SUCCESS);
}
