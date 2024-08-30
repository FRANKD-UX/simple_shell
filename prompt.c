#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints a prompt, reads user input, and prints it
 *
 * Return: Always 0.
 */
int main(void)
{
char *line = NULL;/* Pointer to hold the input line */
size_t len = 0;/* Size of the allocated buffer */
ssize_t read;/*Number of characters read */

while (1) {
        /* Print the prompt */
	printf("$ ");

        /* Read the input line from the user */
	read = getline(&line, &len, stdin);

        /* Check if getline encountered end-of-file or an error */
	if (read == -1) {
	if (feof(stdin)) {
                /* End-of-file reached (Ctrl+D) */
		printf("\nEnd of input (EOF) detected. Exiting...\n");
		break;
            } else {
                /* Error occurred */
		perror("getline");
		free(line);
		return (1);
		}
	}

        /* Print the entered command */
	printf("%s", line);
	}

    /* Free allocated memory */
	free(line);

	return (0);
}
