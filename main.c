#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point of the shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, or appropriate error code
 */
int main(int argc, char **argv)
{
	if (isatty(STDIN_FILENO)) /* Check if running in interactive mode */
		run_interactive_mode();
	else /* Otherwise, run in non-interactive mode */
		run_non_interactive_mode();
	return (0);
}

/**
 * run_interactive_mode - Handles shell in interactive mode
 */
void run_interactive_mode(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4); /* Display prompt */
		nread = getline(&line, &len, stdin); /* Read user input */
		if (nread == -1) /* End of input (Ctrl+D) */
		{
			free(line);
			break;
		}

		execute_command(line); /* Process the command */
	}

	free(line);
}

/**
 * run_non_interactive_mode - Handles shell in non-interactive mode
 */
void run_non_interactive_mode(void)
{
	/*char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while ((nread = getline(&line, &len, stdin)) != -1)
		execute_command(line); /* Process each line of input */

	free(line);
}

/**
 * execute_command - Parses and executes a shell command
 * @command: Command to execute
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char *args[2];

	/* For simplicity, assuming the command has no arguments */
	args[0] = command;
	args[1] = NULL;

	pid = fork(); /* Create a new process */
	if (pid == 0) /* Child process */
	{
		if (execve(command, args, NULL) == -1)
			perror("./hsh");
		_exit(EXIT_FAILURE);
	}
	else if (pid > 0) /* Parent process */
		wait(&status); /* Wait for child to finish */
	else
		perror("fork");
}
