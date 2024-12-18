#include "shell.h"

/* Function prototypes */
void display_prompt(void);
char *read_command(void);
void execute_command(char *line);

/**
 * main - Entry point for the simple shell program.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	char *line;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt(); /* Display prompt in interactive mode */

		line = read_command(); /* Read user input */
		if (!line) /* Handle EOF (Ctrl+D) */
			exit(EXIT_SUCCESS);

		if (_strcmp(line, "exit") == 0) /* Exit command */
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		execute_command(line); /* Execute the command */
		free(line);
	}

	return (0);
}

/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "($) ", 4);
}

/**
 * read_command - Reads a command from standard input.
 *
 * Return: The command string (dynamically allocated).
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1) /* Handle EOF */
	{
		free(line);
		return (NULL);
	}

	/* Remove newline character */
	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}

/**
 * execute_command - Forks and executes a command.
 * @line: The command to execute.
 */
void execute_command(char *line)
{
	pid_t pid;
	int status;
	char *args[2];

	args[0] = line; /* Assign the command to the first argument */
	args[1] = NULL; /* Null-terminate the arguments array */

	pid = fork(); /* Create a child process */
	if (pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) /* Child process */
	{
		if (execve(line, args, environ) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else /* Parent process */
	{
		wait(&status); /* Wait for child to finish */
	}
}

