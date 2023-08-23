#include "shell.h"

/**
 * _getline - reads the commandline
 *
 * Return: line
 */
char *_getline(void)
{
	char *line = NULL;
	size_t size = 0;
	int r = 0;

	if (getline(&line, &size, stdin) == -1)
	{
		free(line);
		exit(-1);
	}
	r = _strlen(line);
	line[r - 1] = '\0';

	return (line);
}

/**
 * sig_hd - to checks if Ctrl C is pressed.
 *
 * @sig_num: int of signal number.
 */
void sig_hd(int sig_num)
{
	if (sig_num == SIGINT)
	{
		print("\nsh$ ");
	}
}

/**
 * execute - the execute a commands.
 *
 * @av: the array of arguments(commands arguments).
 */
int execute(char **av)
{
	pid_t pid;
	int st;

	pid = fork();
	if (pid == 0)
	{
		if (execve(av[0], av, NULL) == -1)
		{
			perror(av[0]);
			exit(1);
		}
	}
	else if (pid > 0)
	{
		wait(&st);
	}
	else
		perror("Error:");

	return (0);
}

/**
 * _realloc - the reallocates memory for previous pointer.
 *
 * @ptr: the previous pointer to reallocate.
 * @old_size: the old size of previous pointer.
 * @new_size: the new size for our pointer.
 *
 * Return: NULL or the new resized pointer.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{

	char *new;
	unsigned int x;

	if (ptr == NULL)
	{
		new = malloc(new_size);
		return (new);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new = malloc(new_size);

	if (new == NULL)
		return (NULL);

	for (x = 0; x < old_size; x++)
	{
		new[x] = ((char *)ptr)[x];
	}

	free(ptr);

	return (new);
}
