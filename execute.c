#include "main.h"

/**
 * execute_command - Executes an external command.
 *
 * @cmd: The command to execute.
 * @args: An array of arguments for the command.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int execute_command(char *cmd, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}
	else if (pid == 0)
	{
		if (execve(cmd, args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("waitpid");
				return (0);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

/**
 * parse_command - Parses the input command.
 *
 * @input: The input string.
 *
 * Return: An array of arguments.
 */
char **parse_command(char *input)
{
	char **args;
	char *token;
	int i = 0;

	args = malloc(sizeof(char *) * MAX_ARGS);
	if (args == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(input, " \n");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;

	return (args);
}

/**
 * handle_input - Handles the input command.
 *
 * @input: The input string.
 *
 * Return: 1 if the command was handled, 0 otherwise.
 */
int handle_input(char *input)
{
	char **args;
	char *cmd;

	args = parse_command(input);
	if (args == NULL)
	{
		return (0);
	}

	cmd = args[0];
	if (cmd == NULL)
	{
		free(args);
		return (0);
	}

	if (execute_command(cmd, args) == 0)
	{
		free(args);
		return (0);
	}

	free(args);
	return (1);
}

