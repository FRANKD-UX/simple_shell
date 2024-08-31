#include "my_getline.h"
#include <stdlib.h>
#include <unistd.h>


/**
 * my_getline - Reads a line from a stream.
 * @lineptr: Pointer to the buffer to store the line.
 * @n: Pointer to the size of the buffer.
 * @stream: The stream to read from.
 * @num_chars: Number of characters read
 * Return: The number of characters read, or -1 on error.
 */
<<<<<<< HEAD
static ssize_t read_input(char **lineptr, size_t *n, FILE * stream,
	ssize_t *num_chars);
static int handle_realloc(char **buffer, size_t *bufsize, ssize_t num_chars);
=======
static ssize_t read input(char **lineptr, size_t *n, FILE *stream,
			ssize_t *num_chars)
static int handle_realloc(char **buffer, size_t *bufsize, ssize_t num_chars)
>>>>>>> 485ca7597b1fedc1ec4afad07eaa71b2f9714bc6
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t num_chars = 0;
	size_t bufsize = 0;
	char *buffer = NULL;

	if (lineptr == NULL || n == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		bufsize = 128;
		buffer = malloc(bufsize);
		if (buffer == NULL)
			return (-1);
		*lineptr = buffer;
		*n = bufsize;
	}
	else
	{
		buffer = *lineptr;
		bufsize = *n;
	}

	return (read_input(lineptr, n, stream, &num_chars));
}

/**
 * read_input - Reads characters from a stream.
 * @lineptr: Pointer to the buffer to store the line.
 * @n: Pointer to the size of the buffer.
 * @stream: The stream to read from.
 * @num_chars: Pointer to the number of characters read.
 *
 * Return: The number of characters read, or -1 on error.
 */
static ssize_t read_input(char **lineptr, size_t *n, FILE *stream,
	ssize_t *num_chars)
{
	char *buffer = *lineptr;
	size_t bufsize = *n;

	while (1)
	{
		ssize_t bytes_read = read(fileno(stream), buffer + *num_chars, 1);

		if (bytes_read == -1 || (bytes_read == 0 && *num_chars == 0))
			return (-1);

		if (bytes_read == 0 || buffer[*num_chars] == '\n')
		{
			buffer[*num_chars] = '\0';
			return (*num_chars);
		}

		(*num_chars)++;

		if (handle_realloc(&buffer, &bufsize, *num_chars) == -1)
			return (-1);

		*lineptr = buffer;
		*n = bufsize;
	}
}

/**
 * handle_realloc - Handles buffer reallocation when needed.
 * @buffer: Double pointer to the buffer.
 * @bufsize: Pointer to the current buffer size.
 * @num_chars: Number of characters currently in the buffer.
 *
 * Return: 0 on success, -1 on failure.
 */
static int handle_realloc(char **buffer, size_t *bufsize, ssize_t num_chars)
{
	if (num_chars + 1 >= *bufsize)
	{
		char *new_buffer = realloc(*buffer, *bufsize * 2);

		if (new_buffer == NULL)
			return (-1);

		*buffer = new_buffer;
		*bufsize *= 2;
	}

	return (0);
}

