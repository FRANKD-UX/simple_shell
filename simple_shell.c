#include "simple_shell.h" /* Your header file */
#include <string.h>       /* Include for strtok function */

/**
 * shell_loop - Runs the shell loop to read and execute commands.
 */
void shell_loop(void)
{
	char *input = NULL; /* Pointer for command input */
	size_t len = 0; /* Size of the input buffer */
	char **args; /* Array of command arguments */

	while (1)
	{
		printf("$ "); /* Display prompt */
		getline(&input, &len, stdin); /* Read input from user */
		args = split_input(input); /* Split input into arguments */

		if (args[0] != NULL) /* If there is a command */
		{
			execute_command(args); /* Execute the command */
		}

		free(args); /* Free allocated memory for arguments */
	}

	free(input); /* Free input buffer */
}

/**
 * execute_command - Executes a command given as arguments.
 * @args: An array of command line arguments.
 */
void execute_command(char **args)
{
	pid_t pid; /* Process ID */
	int status; /* Variable to store exit status */

	pid = fork(); /* Create a new process */
	if (pid == -1)
	{
		perror("Error: Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) /* Child process */
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error: Execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else /* Parent process */
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * split_input - Splits input string into an array of arguments.
 * @input: The input string to split.
 *
 * Return: An array of strings (arguments).
 */
char **split_input(char *input)
{
	int bufsize = 64; /* Initial buffer size for arguments */
	int position = 0; /* Current position in the array */
	char **tokens = malloc(bufsize * sizeof(char *)); /* Allocate memory */
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " \n"); /* Tokenize input */
	while (token != NULL)
	{
		tokens[position++] = token; /* Add token to the array */

		if (position >= bufsize) /* Reallocate if necessary */
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \n"); /* Get next token */
	}
	tokens[position] = NULL; /* Null-terminate the array */
	return (tokens);
}

