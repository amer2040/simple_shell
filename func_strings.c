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

	while (*s)
	{
		x++;
		s++;
	}
	return (x);
}

/**
 * _strdup - duplicate string given as parameter and copy it togather
 *
 * @str: pointer to a string
 *
 * Return: pointer to a string
 */
char *_strdup(char *str)
{
	int x, len;
	char *new;

	if (!str)
	{
		return (NULL);
	}
	len = _strlen(str);

	new = malloc(sizeof(char) * (len + 1));
	if (!new)
	{
		return (NULL);
	}
	for (x = 0; *str != '\0'; str++; x++)
	{
		new[x] = str[0];
	}
	new[x++] = '\0';
	return (new);
}

/**
 * _strcat - concnats 3 strings in a newly allocated memory
 * @name: first string
 * @sep: second string
 * @value: Third string
 * Return: pointer to the new string
 */
char *_strcat(char *name, char *sep, char *value)
{
	char *result;
	int s1, s2, s3, x, y;

	s1 = _strlen(name);
	s2 = _strlen(sep);
	s3 = _strlen(value);

	result = malloc(s1 + s2 + s3 + 1);
	if (!result)
		return (NULL);

	for (x = 0; name[x]; x++)
		result[x] = name[x];
	y = x;

	for (x = 0; sep[x]; x++)
		result[y + x] = sep[x];
	y = y + x;

	for (x = 0; value[x]; x++)
		result[y + x] = value[x];
	y = y + x;

	result[y] = '\0';

	return (result);
}

/**
 * _atoi - converts a ASCII into an integer
 *
 *@s: pointer to a string
 *
 *Return: the integer
 */
int _atoi(char *s)
{
	int i = 0;
	int n = 0;
	int sign = 1;

	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
	{
		if (s[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		n = (n * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (n);
}

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
	int x = 0;
	int cw = 3;
	char **array;
	char *token;
	char *cpy;

	cpy = malloc(_strlen(str) + 1);
	if (cpy == NULL)
	{
		perror("Error");
		return (NULL);
	}
	while (str[x])
	{
		cpy[x] = str[x];
		x++;
	}
	cpy[x] = '\0';

	token = strtok(cpy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(token);

	x = 1;
	while (token)
	{
		token = strtok(NULL, delim);
		array = _realloc(array, (sizeof(char *) * (cw - 1)), (sizeof(char *) * cw));
		array[x] = _strdup(token);
		x++;
		cw++;
	}
	free(cpy);
	return (array);
}
