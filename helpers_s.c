#include "shell.h"

/**
 * str_length - returns the length of a string.
 * @string: pointer to string.
 * Return: length of string.
 * Authors: Frank Ndlovu and Nomcebo Mncina
 */

int str_length(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);

	while (string[length++] != '\0')
	{
	}
	return (--length);
}

/**
 * str_duplicate - Duplicates string
 * @string: String to be copied
 * Return: Pointer to the array
 */

char *str_duplicate(char *string)
{
	char *result;
	int length, x;

	if (string == NULL)
		return (NULL);

	length = str_length(string) + 1;

	result = malloc(sizeof(char) * length);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (x = 0; x < length ; x++)
	{
		result[x] = string[x];
	}

	return (result);
}

/**
 * str_compare - Compare two strings
 * @str1: String one, or the shorter
 * @str2: String two, or the longer
 * @number: The number of characters to be compared, 0 if infinite
 * Return: 1 if the strings are equals,0 if the strings are different
 */
int str_compare(char *str1, char *str2, int number)
{
	int i;

	if (str1 == NULL && str2 == NULL)
		return (1);

	if (str1 == NULL || str2 == NULL)
		return (0);

	if (number == 0)
	{
		if (str_length(str1) != str_length(str2))
			return (0);
		for (i = 0; str1[i]; i++)
		{
			if (str1[i] != str2[i])
				return (0);
		}
		return (1);
	}
	else
	{
		for (i = 0; i < number ; i++)
		{
			if (str1[i] != str2[i])
			return (0);
		}
		return (1);
	}
}

/**
 * str_concat – Function that concatenates two strings.
 * @str1: String to be concatenated
 * @str2: String to be concatenated
 * Return: Pointer to the array
 */
char *str_concat(char *str1, char *str2)
{
	char *result;
	int length1 = 0, length2 = 0;

	if (str1 == NULL)
		str1 = "";
	length1 = str_length(str1);

	if (str2 == NULL)
		str2 = "";
	length2 = str_length(str2);

	result = malloc(sizeof(char) * (length1 + length2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	for (length1 = 0; str1[length1] != '\0'; length1++)
		result[length1] = str1[length1];
	free(str1);

	for (length2 = 0; str2[length2] != '\0'; length2++)
	{
		result[length1] = str2[length2];
		length1++;
	}

	result[length1] = '\0';
	return (result);
}

/**
 * str_reverse - Function that everses a string.
 * @string: The pointer to a string.
 * Return: Returns void.
 */

void str_reverse(char *string)
{

	int x = 0, length = str_length(string) - 1;
	char hold;

	while (x < length)
	{
		hold = string[x];
		string[x++] = string[length];
		string[length--] = hold;
	}
}
