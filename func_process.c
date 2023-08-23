#include "shell.h"

/**
 * sup_process - function that creates a sub process.
 *
 * @av: pointer to tokenized command.
 * @name: The pointer to the name of shell.
 * @environ: The pointer to the enviromental variables.
 * @cy: The number of executed cycles.
 *
 * Return: Nothing.
 */
void sup_process(char **av, char *name, char **environ, int cy)
{
	int pid = 0;
	int st = 0;
	int werror = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		exitfree(av);
	}
	else if (pid == 0)
	{
		execute(av, name, environ, cy);
		freeav(av);
	}
	else
	{
		werror = waitpid(pid, &st, 0);
		if (werror < 0)
		{
			exitfree(av);
		}
		freeav(av);
	}
}


/**
  * _cd - Afunction that changes working directory.
  *
  * @path: new current working directory.
  *
  * Return: 0 on success, -1 on failure.
  */
int _cd(const char *path)
{
	size_t size = 1024;
	char *buf = NULL;

	if (path == NULL)
		path = getcwd(buf, size);
	else if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}

/**
  * interactive - verify if in interactive mode or not.
  */
void interactive(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "sh$ ", 4);
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
		write(STDOUT_FILENO, "\nsh$ ", 5);
	}
}

/**
* _EOF - to handles the End of File.
*
* @buf: buffer.
 */
void _EOF(char *buf)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buf);
	exit(EXIT_SUCCESS);
}
