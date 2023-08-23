#include "shell.h"

/**
 * _strlen - return length of a string
 *
 * @s: pointer to the string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int x = 0;

	while (*(s + x) != '\0')
	{
		x++;
	}
	return (x);
}

/**
 * _strdup - duplicate string given as parameter and copy it togather
 *
 * @str: pointer to a string
 *
 * Return: pointer to a array
 */
char *_strdup(char *str)
{
	char *new;
	int x;

	if (str == NULL)
		return (NULL);

	new = malloc(_strlen(str) + 1);

	if (new == NULL)
		return (NULL);

	x = 0;

	while (str[x] != '\0')
	{
		new[x] = str[x];
		x++;
	}

	new[x] = '\0';

	return (new);
}

/**
 * _strcat - concntenates 2 strings in a newly allocated memory
 *
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the new string
 */
char *_strcat(char *dest, char *src)
{
	int x, y;

	for (x = 0; dest[x] != '\0'; x++)
	{ }

	for (y = 0; src[y] != '\0'; y++, y++)
		dest[x] = src[y];

	dest[x] = '\0';
	return (dest);
}

/**
 * tokinizer - splits a string and makes it an array of words
 *
 * @str: the string to be split
 * @delim: the delimiter
 *
 * Return: array of pointers > words
 */

char **tokinizer(char *str, const char *delim)
{
	char **token;
	int buf = 512;
	int x = 0;

	token = malloc(sizeof(char *) * buf);
	if (!token)
		exit(99);

	token[x] = strtok(str, delim);
	x++;
	while (1)
	{
		token[x] = strtok(NULL, delim);
		if (x >= buf)
		{
			buf += buf;
			token = _realloc(token, buf, buf * (sizeof(char *)));
			if (!token)
				exit(98);
		}
		if (token[x] == NULL)
			break;
		x++;
	}
	return (token);
}
