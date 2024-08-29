#include "shell.h"
/**
 * *_strtok - uses delimiters to separate strings
 * @line: A pointer to array received in fetch.
 * @del: Characters marked off in string parts.
 * return: A pointer to the beginning of the next token on success.
 *Returns NULL if no more tokens are found or if the input string is empty.
*/
char *_strtok(char *line, char *del)
{
	int y;
	char *copystring; /* Pointer to a character array (string)*/
	static char *str; /* Static pointer to a character array (string)*/

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++) /* loop process character in the string*/
	{
		for (y = 0; del[y] != '\0'; y++)
		{
			if (*str == del[y])
			break;
		}
		if (del[y] == '\0')
			break;
	}
	copystring = str;
	if (*copystring == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
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
