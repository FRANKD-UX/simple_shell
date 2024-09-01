#ifndef MY_GETLINE_H
#define MY_GETLINE_H

#include <stddef.h>

/**
 * my_getline - Reads a line from stdin.
 * @lineptr: Pointer to a buffer where the line will be stored.
 * @n: Pointer to the size of the buffer.
 *
 * Return: The number of characters read, or -1 on error.
 */
ssize_t my_getline(char **lineptr, size_t *n);

#endif /* MY_GETLINE_H */

