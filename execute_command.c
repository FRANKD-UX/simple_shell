#include "shell.h"

/**
 * execute_command - Executes a command using execve
 * @argv: Array of arguments for execve
 */
void execute_command(char *argv[])
{
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror(argv[0]); /* Print error if execve fails */
	}
}

