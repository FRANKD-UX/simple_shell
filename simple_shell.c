#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * execute_command - Entry point of the shell.
 * @command: Argument count.
 *
 * Return: Always 0 (Success).
 */
/*int main(int argc, char **argv, char **envp)*/
void execute_command(char *command)
{
	char buffer[1024];
	/**size_t command_length = 0; */

	(void)command;/*Unused paramenet*/

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

