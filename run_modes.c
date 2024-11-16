#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * run_interactive_mode - Runs the shell in interactive mode
 */
void run_interactive_mode(void)
{
	char *line = NULL;
	size_t len = 0;

	while (1)
	{
		printf("$ ");
		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			break;
		}
		execute_command(line);
	}
}

/**
 * run_non_interactive_mode - Executes commands from a file
 * @script_path: Path to the script file
 */
void run_non_interactive_mode(const char *script_path)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;

	file = fopen(script_path, "r");
	if (!file)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		execute_command(line);
	}
	free(line);
	fclose(file);
}

