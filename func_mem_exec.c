#include "shell.h"

/**
  * interactive - verify if in interactive mode or not.
  */
void interactive(void)
{
	if (isatty(STDIN_FILENO))
		print("sh$ ");
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
void execute(char **av)
{

	pid_t pid;
	int st;

	if (!av || !av[0])
		return;
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
	}
	if (pid == 0)
	{
		execve(av[0], av, environ);
		perror(av[0]);
		exit(EXIT_FAILURE);
	}
	wait(&st);
}

/**
 * _realloc - the reallocates memory for previous pointer.
 *
 * @ptr: the previous pointer to reallocate.
 * @old_size: the old size of previous pointer.
 * @new_size: the new size for our pointer.
 *
 * Return: the new resized pointer.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;
	unsigned int x;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (x = 0; x < old_size; x++)
			new[x] = old[x];
		free(ptr);
		for (x = old_size; x < new_size; x++)
			new[x] = '\0';
	}
	if (new_size < old_size)
	{
		for (x = 0; x < new_size; x++)
			new[x] = old[x];
		free(ptr);
	}
	return (new);
}

/**
* _EOF - to handles the End of File.
*
* @len: length og line.
* @buf: buffer.
 */
void _EOF(int len, char *buf)
{
	(void)buf;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			print("\n");
			free(buf);
		}
		exit(0);
	}
}