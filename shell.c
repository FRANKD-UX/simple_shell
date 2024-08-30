#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * execute_command - Executes a command using execve.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
	char *args[2];

	args[0] = command;
	args[1] = NULL;

	if (execve(command, args, NULL) == -1)
	{
		perror("execve");
	}
}

/**
 * main - Entry point of the shell program.
 *
 * This function repeatedly prompts the user for input, reads the command,
 * and executes it. It handles EOF to exit gracefully.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("$ ");  /* Print prompt */

		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			if (feof(stdin))  /* EOF reached */
			{
				printf("\n");
				free(line);
				return (EXIT_SUCCESS);
			}
			else
			{
				perror("getline");
				free(line);
				return (EXIT_FAILURE);
			}
		}

		/* Remove newline character if present */
		if (line[nread - 1] == '\n')
		{
			line[nread - 1] = '\0';
		}

		/* Execute the command */
		execute_command(line);
	}

	free(line);
	return (EXIT_SUCCESS);
}

