#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * run_interactive_mode - Handles shell in interactive mode
 */
void run_interactive_mode(void)
{
	char *line = NULL;
	size_t len = 0;

	printf("$ "); /* Shell prompt */
	while (getline(&line, &len, stdin) != -1)
	{
		execute_command(line); /* Process the command */
		printf("$ ");
	}

	free(line); /* Free allocated memory */
}

