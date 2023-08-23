#include "shell.h"

/**
 * _which - finds the full pathname of a filename.
 *
 * @filename: the name of file or command given.
 * @head: the head of linked list of path directories.
 *
 * Return: Full pathname of filename or NULL if no match.
 */
char *_which(char *filename, lpath *head)
{
	lpath *tmp = head;
	struct stat st;
	char *str;

	while (tmp)
	{

		str = _strcat(tmp->dir, "/", filename);
		if (stat(str, &st) == 0)
		{
			return (str);
		}
		free(str);
		tmp = tmp->np;
	}

	return (NULL);
}

/**
 * sh_exit - exit from shell.
 *
 * @av: the array of words (commands arguments).
*/
void sh_exit(char **av)
{
	int x, y;

	if (av[1])
	{
		y = _atoi(av[1]);
		if (y <= -1)
		{
			y = 2;
		}
		freeav(av);
		exit(y);
	}
	for (x = 0; av[x]; x++)
		free(av[x]);
	free(av);
	exit(0);
}

/**
* cmd_check - To checks command is a buildin or not.
*
* @av: the array of arguments.
*
* Return: the pointer to function that takes av and returns void.
*/
void(*cmd_check(char **av))(char **av)
{
	int x, y;
	shbuildin shbin[] = {
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"exit", sh_exit},
		{NULL, NULL}
	};

	for (x = 0; shbin[x].ncmd; x++)
	{
		y = 0;
		if (shbin[x].ncmd[y] == av[0][y])
		{
			for (y = 0; av[0][y]; y++)
			{
				if (shbin[x].ncmd[y] != av[0][y])
					break;
			}
			if (!av[0][y])
				return (shbin[x].func);
		}
	}
	return (0);
}
