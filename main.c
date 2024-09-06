#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - Entry point of the shell program.
 * @argc: Number of command line arguments.
 * @argv: Array of command line arguments.
 * @envp: Array of environment variables.
 *
 * Return: Always 0 (Success).
 */
int main(int argc, char **argv, char **envp)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	(void)argc; /* Unused parameter */
	(void)argv; /* Unused parameter */
	(void)envp; /* Unused parameter */

	while (1)
	{
		printf("$ "); /* Print the prompt */
		fflush(stdout);

		/* Get user input */
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == -1)
		{
			perror("getline");
			free(buffer);
			exit(EXIT_FAILURE);
		}

		/* Remove newline character if present */
		if (buffer[characters - 1] == '\n')
		{
			buffer[characters - 1] = '\0';
		}

		printf("Command entered: %s\n", buffer); /* Debug output */

		/* Execute the command */
		execute_command(buffer);
	}

	free(buffer);
	return (0);
}

