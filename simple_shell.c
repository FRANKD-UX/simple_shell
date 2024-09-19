#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

#define BUFFER_SIZE 1024
#define PROMPT "#cisfun$ "

/**
 * main - Entry point of the shell program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char *argv[])
{
	(void)argc; /* Suppress unused parameter warning */
	char buffer[BUFFER_SIZE];
	int status;
	pid_t pid;

	while (1)
	{
		printf(PROMPT);

		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			perror("fgets");
			continue;
		}

		buffer[strcspn(buffer, "\n")] = '\0'; /* Remove newline character */

		if (strcmp(buffer, "exit") == 0)
			break;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			continue;
		}
		else if (pid == 0)
		{
			/* Child process */
			char *args[] = {buffer, NULL};
			if (execve(args[0], args, environ) == -1)
			{
				perror(argv[0]);
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			/* Parent process */
			wait(&status);
		}
	}

	return (0);
}

/**
 * execute_command - Executes a command
 * @command: The command to execute
 * @argv: Argument vector
 */
void execute_command(char *command, char *argv[])
{
	char *args[2];
	int status;
	pid_t pid;

	args[0] = command;
	args[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, environ) == -1)
		{
			perror(argv[0]);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		wait(&status);
	}
}

