<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
=======
>>>>>>> c64403caa714f45e9ab0372a5968a8ff1054a3f5
#include <unistd.h>
#include <string.h>
#include <stdlib.h>  /* For realloc */

/**
 * my_getline - reads an entire line from standard input
 * @lineptr: pointer to a buffer where the line will be stored
 * @n: size of the buffer
 *
 * Return: the number of characters read, or -1 on failure.
 */
ssize_t my_getline(char **lineptr, size_t *n)
{
	char buffer[128];
	ssize_t bytes_read;
	size_t len = 0;

	if (lineptr == NULL || n == NULL)
		return (-1);

	*lineptr = NULL;
	*n = 0;

	while ((bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1)) > 0)
	{
		if (len + bytes_read > *n)
		{
			*n = len + bytes_read + 1;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
		}

		memcpy(*lineptr + len, buffer, bytes_read);
		len += bytes_read;
	}

	if (bytes_read == -1)
		return (-1);

	if (len == 0 && bytes_read == 0)
		return (0);

	(*lineptr)[len] = '\0';
	return (len);
}

