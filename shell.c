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
