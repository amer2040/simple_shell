#include "shell.h"

/**
 * main - entry point.
 *
 * @ac: arguments count.
 * @av: arguments vector.
 * @environ: pointer to array of enviromental variables.
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **environ)
{
	char *buf = NULL;
	char **command = NULL;
	size_t buf_size = 0;
	ssize_t ch_readed = 0;
	int cy = 0;
	(void)ac;

	while (1)
	{
		cy++;
		interactive();
		signal(SIGINT, sig_hd);
		ch_readed = getline(&buf, &buf_size, stdin);
		if (ch_readed == EOF)
			_EOF(buf);
		else if (*buf == '\n')
			free(buf);
		else
		{
			buf[_strlen(buf) - 1] = '\0';
			command = split_string(buf, " \0");
			free(buf);
			if (_strcmp(command[0], "exit") != 0)
				sh_exit(command);
			else if (_strcmp(command[0], "cd") != 0)
				_cd(command[1]);
			else
				sup_process(command, av[0], environ, cy);
		}
		fflush(stdin);
		buf = NULL, buf_size = 0;
	}
	if (ch_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
