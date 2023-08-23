#include "shell.h"

/**
 * _putchar - writes the character c
 *
 * @c: The character to print
 *
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print - prints a strings
 *
 * @str: pointer to string
 *
 * Return: characters count number.
 */
void print(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}
