#include "shell.h"

/* Function prototypes */
void display_prompt(void);
char *read_command(void);
void execute_command(char *line);

/**
 * main - Entry point for the simple shell
 *
 * Return: 0 on success, or an appropriate error code
 */
int main(void)
{
	char *line;

	while (1)
	{
		/* Display prompt */
		if (isatty(STDIN_FILENO))
			display_prompt();

		/* Read input from user */
		line = read_command();
		if (!line) /* Handle EOF (Ctrl+D) */
			break;

		/* Execute the command */
		execute_command(line);

		free(line);
	}

	return (0);
}

/**
 * display_prompt - Displays the shell prompt
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "($) ", 4);
}

/**
 * read_command - Reads a command from standard input
 *
 * Return: Pointer to the command string, or NULL on EOF
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
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		return (NULL);
	}

	/* Remove trailing newline character */
	line[nread - 1] = '\0';
	return (line);
}

/**
 * execute_command - Forks a process and executes a command
 * @line: Command string
 */
void execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[2];

	/* Prepare argv for execve */
	argv[0] = line; /* Command */
	argv[1] = NULL; /* Null-terminate the argument list */

	/* Fork a child process */
	pid = fork();
	if (pid == 0) /* Child process */
	{
		if (execve(argv[0], argv, environ) == -1) /* Execute command */
		{
			perror(argv[0]); /* Print error message */
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) /* Fork error */
	{
		perror("fork");
	}
	else /* Parent process */
	{
		wait(&status); /* Wait for child to finish */
	}
}

