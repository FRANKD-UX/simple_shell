#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PROMPT "#cisfun$ "

void handle_input(char *input);
void remove_newline(char *input);
void execute_command(char *input);

/**
 * main - Entry point for the simple shell
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
		nread = getline(&input, &len, stdin);

		if (nread == -1) /* Handle EOF */
		{
			if (feof(stdin))
			{
				free(input);
				write(STDOUT_FILENO, "\n", 1);
				exit(EXIT_SUCCESS);
			}
			perror("getline");
			exit(EXIT_FAILURE);
		}

		handle_input(input);
	}

	free(input);
	return (0);
}

/**
 * handle_input - Processes the user input
 * @input: User input string
 */
void handle_input(char *input)
{
	remove_newline(input);
	execute_command(input);
}

/**
 * remove_newline - Removes newline character from input
 * @input: User input string
 */
void remove_newline(char *input)
{
	size_t len = strlen(input);

	if (input[len - 1] == '\n')
		input[len - 1] = '\0';
}

/**
 * execute_command - Forks and executes the command
 * @input: Command to execute
 */
void execute_command(char *input)
{
	pid_t pid;
	int status;
	char *args[] = {NULL}; /* args is an array of pointers to command arguments */

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) /* Child process */
	{
		execve(input, args, NULL);
		perror(input);
		exit(EXIT_FAILURE);
	}
	else /* Parent process */
	{
		waitpid(pid, &status, 0);
	}
}

