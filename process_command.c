#include "shell.h"

/**
 * process_command - Processes a given command line
 * @line: The command line input
 */
void process_command(char *line)
{
	char **args;

	args = tokenize_input(line); /* Use the correct tokenizer function */
	if (args == NULL)
		return;

	/* Example: Execute command or handle built-ins */
	if (strcmp(args[0], "exit") == 0)
		handle_exit(args);
	else if (strcmp(args[0], "cd") == 0)
		handle_cd(args);
	else if (strcmp(args[0], "env") == 0)
		handle_env();
	else
		execve(args[0], args, environ);

	free_tokens(args);
}
