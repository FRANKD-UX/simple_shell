#include "shell.h"
/**
 * _strtok - uses delimiters to separate strings
 * @line: A pointer to array received in fetch.
 * @del: Characters marked off in string parts.
 * return: Pointer to the token created
*/
char *_strtok(char *line, char *del)
{
	int y;
	char *copystring; /* Pointer to a character array (string)*/
	static char *str; /* Static pointer to a character array (string)*/

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++) /* This loop will process each character in the string*/
	{
		for (y = 0; del[y] != '\0'; y++) /* Check if the current character pointed to by 'str' matches the delimiter at index 'y'*/
		{
			if (*str == del[y])
			break;
		}
		if (del[y] == '\0') /* If no matching delimiter is found (i.e., the end of 'delim' is reached), exit the outer loop.*/
			break;
	}
	copystring = str;
	if (*copystring == '\0')
		return (NULL);
	for (; *str != '\0'; str++) /* loop is used to traverse each character in the string pointed to by ‘str’*/
	{
		for (y = 0; del[y] != '\0'; y++)
		{
			if (*str == del[y])
			{
				*str = '\0';
				str++;
				return (copystring);
			}
		}
	}
	return (copystring);
}
/*This code is by Frank Ndlovu and Nomcebo Mncina*/
