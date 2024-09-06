#include "main.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * execute_command - Execute a command.
 * @cmd: Command to execute.
 */
void execute_command(char *cmd)
{
	struct stat st;
	char *args[2];

	if (stat(cmd, &st) == -1)
	{
		perror(cmd);
		exit(EXIT_FAILURE);
	}

	args[0] = cmd;
	args[1] = NULL;

	if (execve(cmd, args, NULL) == -1)
	{
		perror(cmd);
		exit(EXIT_FAILURE);
	}
}

