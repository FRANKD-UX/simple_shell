#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * execute_command - Executes a command provided by the user.
 * @command: The command to execute.
 */
void execute_command(char *command);

/**
 * main - Entry point of the shell.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *command = NULL;
	size_t len = 0;

	while (1)
	{
		printf("$ "); /* Prompt user */

		/* Read input from the user */
		if (getline(&command, &len, stdin) == -1)
		{
			perror("getline");
			free(command);
			exit(EXIT_FAILURE);
		}

		/* Remove the newline character from the command */
		command[strcspn(command, "\n")] = '\0';

		/* Execute the command */
		execute_command(command);
	}

	free(command); /* Free the command buffer */
	return (0); /* Return success */
}

/**
 * execute_command - Executes a command provided by the user.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
	char *args[4]; /* Adjust size according to your command */
	pid_t pid;

	/* Check for exit command */
	if (strcmp(command, "exit") == 0)
	{
		free(command); /* Free the input buffer */
		exit(0); /* Exit the shell */
	}

	args[0] = "/bin/sh"; /* Shell to execute */
	args[1] = "-c"; /* Argument for shell */
	args[2] = command; /* User command */
	args[3] = NULL; /* Null terminate the args array */

	pid = fork(); /* Create a child process */
	if (pid == 0) /* Child process */
	{
		execve(args[0], args, NULL); /* Execute the command */
		perror("Execution failed"); /* Print error if execve fails */
		exit(EXIT_FAILURE); /* Exit child process */
	}
	else if (pid < 0) /* Fork failed */
	{
		perror("Fork failed");
	}
	else
	{
		wait(NULL); /* Wait for child to finish */
	}
}

