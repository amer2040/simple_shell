#include "shell.h"

/**
 * main - Entry point.
 *
 * Return: 0 Always on success.
 */

int main(void)
{
	char *buf = NULL, *value, *path, **av;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	lpath *head = NULL;
	void (*func)(char **);

	signal(SIGINT, sig_hd);
	while (linesize != EOF)
	{
		interactive();
		linesize = getline(&buf, &bufsize, stdin);
		_EOF(linesize, buf);
		av = split_string(buf, " \n");
		if (!av || !av[0])
			execute(av);
		else
		{
			value = _getenv("PATH");
			head = lk_path(value);
			path = _which(av[0], head);
			func = cmd_check(av);
			if (func)
			{
				free(buf);
				func(av);
			}
			else if (!path)
				execute(av);
			else if (path)
			{
				free(av[0]);
				av[0] = path;
				execute(av);
			}
		}
	}
	free_list(head);
	freeav(av);
	free(buf);
	return (0);
}
