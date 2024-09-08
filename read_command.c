#include "shell.h"

/**
 * read_command - main entry
 * Return: line if the command was handled.
 **/

char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
	perror("getline");
	exit(EXIT_FAILURE);
	}

	return (line);
}
