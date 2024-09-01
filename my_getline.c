#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/* Function Prototypes */
static ssize_t read_input(char **lineptr, size_t *n, FILE *stream);
static int handle_realloc(char **buffer, size_t *bufsize, ssize_t num_chars);

/**
 * handle_realloc - Reallocates the buffer to accommodate more characters.
 * @buffer: Pointer to the buffer to reallocate.
 * @bufsize: Pointer to the current size of the buffer.
 * @num_chars: The number of characters read so far.
 *
 * Return: 0 on success, -1 on failure.
 */
static int handle_realloc(char **buffer, size_t *bufsize, ssize_t num_chars)
{
	/* Cast num_chars to size_t for comparison */
	if ((size_t)num_chars >= *bufsize)
	{
		char *new_buffer;

		*bufsize *= 2;
		new_buffer = realloc(*buffer, *bufsize);
		if (!new_buffer)
		{
			free(*buffer);
			return (-1);
		}
		*buffer = new_buffer;
	}
	return (0);
}

/**
 * read_input - Reads input from a stream into a buffer.
 * @lineptr: Pointer to the buffer where the input is stored.
 * @n: Pointer to the size of the buffer.
 * @stream: The stream to read from (e.g., stdin).
 *
 * Return: The number of characters read, or -1 on failure.
 */
static ssize_t read_input(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t num_chars = 0;
	int ch;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128; /* Initial buffer size */
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while ((ch = fgetc(stream)) != EOF && ch != '\n')
	{
		if (handle_realloc(lineptr, n, num_chars) == -1)
			return (-1);

		(*lineptr)[num_chars++] = ch;
	}

	if (ch == EOF && num_chars == 0)
		return (-1);

	(*lineptr)[num_chars] = '\0';
	return (num_chars);
}

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = read_input(&line, &len, stdin)) != -1)
	{
		printf("You entered: %s\n", line);
	}

	free(line);
	return (0);
}

