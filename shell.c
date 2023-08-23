#include "shell.h"

/**
 * main - Entry point.
 *
 * @ac: arguments count
 * @av: arguments vector
 * @environ: global variable env
 *
 * Return: 0 Always on success.
 */

int main(int ac, char **av, char **environ)
{
	char *line = NULL;
	char *delim = "\t \a\n";
	char *command;
	char **tokens;
	(void)ac;

	tokens = _findpath(environ);

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		line = _getline();
		av = tokinizer(line, delim);
		command = path_args(av, tokens);
		if (command == NULL)
			execute(av);
		free(line);
		free(av);
		free(command);
	}
	return (0);
}
