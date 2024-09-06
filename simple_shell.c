#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point of the shell.
 * @argc: Argument count.
 * @argv: Argument vector.
 * @envp: Environment variables.
 *
 * Return: Always 0 (Success).
 */
int main(int argc, char **argv, char **envp)
{
	char buffer[1024];
	/**size_t command_length = 0; */

	(void)argc; /* unused parameter */
	(void)argv; /* unused parameter */
	(void)envp; /* unused parameter */

	/* Print a prompt */
	printf("$ ");
	if (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		/* Remove newline character if present */
		if (buffer[strlen(buffer) - 1] == '\n')
		{
			buffer[strlen(buffer) - 1] = '\0';
		}

		/* Execute the command */
		execute_command(buffer);
	}
	else
	{
		perror("fgets");
		exit(EXIT_FAILURE);
	}

	return (0);
}

