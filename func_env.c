#include "shell.h"

/**
 * env - prints the current environment
 *
 * @av: array of arguments
 */
void env(char **av __attribute__ ((unused)))
{

	int x = 0;

	while (environ[x])
	{
		write(STDOUT_FILENO, (const void *)environ[x], _strlen(environ[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}

}

/**
 * _getenv - gets the value of the global variable in environment
 *
 * @name: the name of the global variable
 *
 * Return: string of value
 */
char *_getenv(const char *name)
{
	char *value;
	int x, y;

	if (!name)
		return (NULL);
	for (x = 0; environ[x]; x++)
	{
		y = 0;
		if (name[y] == environ[x][y])
		{
			while (name[y])
			{
				if (name[y] != environ[x][y])
					break;

				y++;
			}
			if (name[y] == '\0')
			{
				value = (environ[x] + y + 1);
				return (value);
			}
		}
	}
	return (0);
}

/**
 * _setenv - create or modify environment variable
 *
 * @av: array of words.
 */
void _setenv(char **av)
{
	int x, y, z;

	if (!av[1] || !av[2])
	{
		perror("Error");
		return;
	}

	for (x = 0; environ[x]; x++)
	{
		y = 0;
		if (av[1][y] == environ[x][y])
		{
			while (av[1][y])
			{
				if (av[1][y] != environ[x][y])
					break;

				y++;
			}
			if (av[1][y] == '\0')
			{
				z = 0;
				while (av[2][z])
				{
					environ[x][y + 1 + z] = av[2][z];
					z++;
				}
				environ[x][y + 1 + z] = '\0';
				return;
			}
		}
	}
	if (!environ[x])
	{

		environ[x] = _strcat(av[1], "=", av[2]);
		environ[x + 1] = '\0';

	}
}

/**
 * _unsetenv - Delete an environment variable
 *
 * @av: array of  words.
 */
void _unsetenv(char **av)
{
	int x, y;

	if (!av[1])
	{
		perror("Error");
		return;
	}
	for (x = 0; environ[x]; x++)
	{
		y = 0;
		if (av[1][y] == environ[x][y])
		{
			while (av[1][y])
			{
				if (av[1][y] != environ[x][y])
					break;

				y++;
			}
			if (av[1][y] == '\0')
			{
				free(environ[x]);
				environ[x] = environ[x + 1];
				while (environ[x])
				{
					environ[x] = environ[x + 1];
					x++;
				}
				return;
			}
		}
	}
}

/**
 * freeav - frees the array of pointers av
 *
 *@av: array of pointers.
 */

void freeav(char **av)
{
	int x = 0;

	if (!av || av == NULL)
		return;
	while (av[x])
	{
		free(av[x]);
		x++;
	}
	free(av);
}
