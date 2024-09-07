#include "shell.h"

/**
 * main - Entry point for the shell.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	(void)argc;
	(void)argv;

	while (1)
	{
		prompt();
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		line[read - 1] = '\0'; /* Remove newline character */
		parse_and_execute(line);
	}

	free(line);
	return (0);
}

