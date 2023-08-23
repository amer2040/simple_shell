#include "shell.h"

/**
 * path_args - concatenates the arguments
 *
 * @parse: first string
 * @new: last string
 *
 * Return: all or null
 */

char *path_args(char **parse, char **new)
{
	char *all, **cat;
	int x, y, z;
	struct stat status;

	for (x = 0; new[x]; x++)
	{
		all = malloc(60);
		_strcat(all, new[x]);
		_strcat(all, "/");
		_strcat(all, parse[0]);

		if (stat(all, &status) == 0)
		{
			for (z = 0; parse[z] != NULL; z++)
				;
			cat = malloc(sizeof(char *) * (z + 1));
			cat[z] = NULL;
			cat[0] = _strdup(all);

			for (y = 1; parse[y]; y++)
				cat[y] = _strdup(parse[y]);
			execute(cat);
			return (all);
		}
		free(all);
	}
	return (NULL);
}

/**
 * _findpath - function that finds the path
 *
 * @environ: global variable environment
 *
 * Return: path in tokens
 */

char **_findpath(char **environ)
{
	char *get_path, **tokens, *delim;

	delim = ":";
	get_path = _getenv(environ, "PATH");
	tokens = tokinizer(get_path, delim);
	return (tokens);
}