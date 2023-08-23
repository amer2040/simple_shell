#include "shell.h"

/**
 * _strlen - return length of a string
 *
 * @s: pointer to the string
 *
 * Return: length of string
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (*(s + len) != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcpy - function that copies a string to another string.
 *
 * @dest: pointer of the copyed string
 * @src: pointer of the string to copy for
 *
 * Return: pointer to copied string
 */
char *_strcpy(char *dest, char *src)
{
	char *cpy = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (cpy);
}


/**
 * _strcat - a function that concatenates two strings.
 *
 * @dest: destintion string.
 * @src: source string.
 *
 * Return: A pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	char *tmp = dest;

	while (*dest)
		dest++;

	*dest++ = '/';
	while (*src)
		*dest++ = *src++;
	return (tmp);
}


/**
 * _strcmp - funtion that compares two strings.
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if strings are the same, 0 if not
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int x = 0;

	while (s1[x])
	{
		if (s1[x] != s2[x])
			return (0);
		x++;
	}

	return (1);
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
	int x = 0;
	int n = 0;
	int sign = 1;

	while (!((s[x] >= '0') && (s[x] <= '9')) && (s[x] != '\0'))
	{
		if (s[x] == '-')
		{
			sign = sign * (-1);
		}
		x++;
	}
	while ((s[x] >= '0') && (s[x] <= '9'))
	{
		n = (n * 10) + (sign * (s[x] - '0'));
		x++;
	}
	return (n);
}
