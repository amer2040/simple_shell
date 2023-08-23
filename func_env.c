#include "shell.h"

/**
 * chk_equal - function that checks the ()=) character
 *
 * @str: is a string
 *
 * Return: str
 */

char *chk_equal(char *str)
{
	int x;

	for (x = 0; str[x] != '='; x++)
		;
	return (str + x + 1);
}

/**
 * comp - function that compares two strings
 *
 * @varname: is a char
 * @dirname: is a char
 *
 * Return: 1
 */

int comp(char *varname, char *dirname)
{
	int x;

	for (x = 0; dirname[x] != '\0'; x++)
	{
		if (dirname[x] != varname[x])
			return (0);
	}
	return (1);
}

/**
 * _getenv - function gets the path in the environ
 *
 * @environ: global variable
 * @dirname: is a char
 *
 * Return: final or null
 */

char *_getenv(char **environ, char *dirname)
{
	int x, y;
	char *varname, *final;

	for (y = 0; environ[y]; y++)
	{
		varname = malloc(512);

		for (x = 0; environ[y][x] != '='; x++)
			varname[x] = environ[y][x];

		if (comp(varname, dirname))
		{
			final = chk_equal(environ[y]);
			free(varname);
			return (final);

		}
		free(varname);
	}
	return (NULL);
}
