#include "shell.h"

/* Function prototypes */
void handle_command(char *command);
char *read_command(void);

/**
 * main - Entry point of the shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *command;

	while (1)
	{
		prompt(); /* Display the shell prompt */

		/* Read the command from the user */
		command = read_command();
		if (command == NULL)
		{
			/* Handle errors or end of file */
			continue;
		}

		/* Process the command */
		handle_command(command);

		/* Free the memory allocated for the command */
		free(command);
	}

	return (0);
}

/**
 * handle_command - Handles the execution of the command
 * @command: The command to execute
 */
void handle_command(char *command)
{
	char *argv[2];
	pid_t pid;
	int status;

	/* Remove trailing newline character */
	command[strcspn(command, "\n")] = '\0';

	/* If the command is empty, do nothing */
	if (strlen(command) == 0)
	{
		return;
	}

	/* Set up arguments for execve (just the command, no arguments) */
	argv[0] = command;
	argv[1] = NULL;

	pid = fork(); /* Fork a new process */

	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		/* Child process: Execute the command */
		execute_command(argv);
	}
	else
	{
		/* Parent process: Wait for the child process to finish */
		wait(&status);
	}
}

/**
 * read_command - Reads a command from the user
 *
 * Return: A dynamically allocated string containing the command
 */
char *read_command(void)
{
	char *command = NULL;
	size_t bufsize = 0;

	if (getline(&command, &bufsize, stdin) == -1)
	{
		/* Handle EOF (Ctrl+D) */
		if (feof(stdin))
		{
			free(command);
			exit(0); /* Exit shell if Ctrl+D is pressed */
		}
		else
		{
			perror("getline"); /* Handle other errors */
			return (NULL);
		}
	}

	return (command);
}

