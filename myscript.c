#define _POSIX_C_SOURCE 200809L /* Enable POSIX features like getline */
#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * run_non_interactive_mode - Handles shell in non-interactive mode
 * @script_path: Path to script file
 */
void run_non_interactive_mode(const char *script_path)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;

	if (!script_path)
	{
		fprintf(stderr, "Error: No script file provided.\n");
		return;
	}

	file = fopen(script_path, "r");
	if (!file)
	{
		perror("Error opening file");
		return;
	}

	while (getline(&line, &len, file) != -1)
		execute_command(line);

	free(line); /* Free allocated memory */
	fclose(file);
}
