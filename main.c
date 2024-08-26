#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t nread;
	char *argv[2];

	while (1)
	{
		printf("#cisfun$ ");
		nread = getline(&buffer, &bufsize, stdin);

		if (nread == -1) /* Handle EOF (Ctrl+D) */
		{
			free(buffer);
			exit(0);
		}

		buffer[nread - 1] = '\0'; /* Remove newline character */

		argv[0] = buffer;
		argv[1] = NULL;

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
		}
	}

	return (0);
}

