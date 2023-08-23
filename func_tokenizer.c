#include "shell.h"


/**
 * split_string - splits a string and makes it an array of words
 *
 * @str: the string to be split
 * @delim: the delimiter
 *
 * Return: array of pointers > words
 */

char **split_string(char *str, const char *delim)
{
	char *token = NULL, **av = NULL;
	size_t strsize = 0;
	int x = 0;

	if (str == NULL)
		return (NULL);

	strsize = _strlen(str);
	av = malloc((strsize + 1) * sizeof(char *));
	if (av == NULL)
	{
		perror("Unable to allocate buffer");
		free(str);
		freeav(av);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);
	while (token != NULL)
	{
		av[x] = malloc(_strlen(token) + 1);
		if (av[x] == NULL)
		{
			perror("Unable to allocate buffer");
			freeav(av);
			return (NULL);
		}
		_strcpy(av[x], token);
		token = strtok(NULL, delim);
		x++;
	}
	av[x] = NULL;
	return (av);
}
