#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void print_prompt(void);
char *read_input(void);
char **parse_input(char *input);
void execute_command(char **args);

/**
 * main - Entry point for the simple shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *input;
	char **args;

	while (1)
	{
		print_prompt();
		input = read_input();
		if (input == NULL)
			break; /* Exit on Ctrl+D */

		args = parse_input(input);
		if (args[0] == NULL)
		{
			free(input);
			free(args);
			continue; /* Skip empty input */
		}

		execute_command(args);

		free(input);
		free(args);
	}

	return (0);
}

/**
 * print_prompt - Prints the shell prompt.
 */
void print_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}

/**
 * read_input - Reads user input from stdin.
 *
 * Return: Pointer to the input string, or NULL on EOF.
 */
char *read_input(void)
{
	char *buffer = malloc(BUFFER_SIZE);

	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(EXIT_FAILURE);
	}

	if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
	{
		free(buffer);
		return (NULL);
	}

	buffer[strcspn(buffer, "\n")] = '\0'; /* Remove newline character */
	return (buffer);
}

/**
 * parse_input - Tokenizes user input into an array of arguments.
 * @input: The input string.
 *
 * Return: Pointer to the array of arguments.
 */
char **parse_input(char *input)
{
	char **args = malloc(10 * sizeof(char *));
	int i = 0;

	if (args == NULL)
	{
		perror("Unable to allocate args");
		exit(EXIT_FAILURE);
	}

	args[i] = strtok(input, " ");
	while (args[i] != NULL && i < 9)
	{
		i++;
		args[i] = strtok(NULL, " ");
	}
	args[9] = NULL;

	return (args);
}

/**
 * execute_command - Forks a child process to execute a command.
 * @args: The command and its arguments.
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, NULL) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		/* Parent process waits */
		wait(&status);
	}
	else
	{
		perror("Fork failed");
	}
}

