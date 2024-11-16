#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute_command - Executes a shell command
 * @command: Command to execute
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char *argv[] = {"/bin/sh", "-c", command, NULL};

	if (!command || *command == '\n')
		return; /* Skip empty commands */

	pid = fork(); /* Create child process */
	if (pid == 0)
	{
		/* Child process */
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error forking");
	}
	else
	{
		/* Parent process waits for child to finish */
		waitpid(pid, &status, 0);
	}
}

