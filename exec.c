#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * execute_command - Execute a command.
 * @cmd: Command to execute.
 */
void execute_command(char *cmd)
{
	char *args[2];

	args[0] = cmd;
	args[1] = NULL;

	if (execve(cmd, args, NULL) == -1)
	{
		perror(cmd);
		exit(EXIT_FAILURE);
	}
}

