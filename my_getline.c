#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * my_getline - Reads a line from stdin.
 * @lineptr: Pointer to a buffer where the line will be stored.
 * @n: Pointer to the size of the buffer.
 * Return: The number of characters read, or -1 on error.
 */
ssize_t my_getline(char **lineptr, size_t *n)
{
	ssize_t len = 0;
	ssize_t read;
	char buffer[128];

	if (lineptr == NULL || n == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*lineptr = malloc(128);
		if (*lineptr == NULL)
			return (-1);
		*n = 128;
	}

	while ((read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[read] = '\0';
		if (len + read > *n)
		{
			*n = len + read;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
		}
		memcpy(*lineptr + len, buffer, read);
		len += read;
		if (buffer[read - 1] == '\n')
			break;
	}

	if (read == -1)
		return (-1);

	(*lineptr)[len] = '\0';
	return (len);
}

