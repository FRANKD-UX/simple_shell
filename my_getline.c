#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INITIAL_BUFFER_SIZE 64

/**
 * my_getline - Custom implementation of getline
 * @lineptr: Pointer to the buffer where the line will be stored
 * @n: Pointer to the size of the buffer
 * @stream: Input stream to read from
 *
 * Return: Number of characters read, or -1 on failure or EOF
 */
static ssize_t read input(char **lineptr, size_t *n, FILE *stream,
			ssize_t *num_chars)
static int handle_realloc(char **buffer, size_t *bufsize, ssize_t num_chars)
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
size_t bufsize = *n;
ssize_t num_chars = 0;
char ch;
char *buffer;

	if (lineptr == NULL || n == NULL || stream == NULL)
	return (-1);
	if (*lineptr == NULL)
	{
		bufsize = INITIAL_BUFFER_SIZE;
		buffer = malloc(bufsize);
	if (buffer == NULL)
		return (-1);
		*lineptr = buffer;
	}
	else
	{
	buffer = *lineptr;
	}
	while (read(fileno(stream), &ch, 1) > 0)
	{
	if (num_chars + 1 >= bufsize)
		{
		bufsize *= 2;
		char *new_buffer = realloc(buffer, bufsize);
	if (new_buffer == NULL)
		return (-1);
		buffer = new_buffer;
		*lineptr = buffer;
	}
	buffer[num_chars++] = ch;
	if (ch == '\n')
		break;
	}
	if (num_chars == 0 && (read(fileno(stream), &ch, 1) <= 0))
	return (-1);
	buffer[num_chars] = '\0';
	*n = bufsize;
	return (num_chars);
}
