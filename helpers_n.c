#include "shell.h"

/**
 * long_to_string - converts a number to a string.
 * @number: Number to be convert in an string.
 * @string: Buffer to save the number as string.
 * @base: Base to convert number
 * Return: Nothing.
 * Authours: Frank Ndlovu and Nomcebo Mncina
 */
void long_to_string(long number, char *string, int base)
{
	int z = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[z++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[z++] = letters[-(cociente % base)];
		else
			string[z++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[z++] = '-';

	string[z] = '\0';
	str_reverse(string);
}

/**
 * _atoi - Convert a string to an integer.
 * @s: Pointer to string origin.
 * Return: int of string or 0.
 */

int _atoi(char *s)
{
	int sigil = 1;
	unsigned int number = 0;

	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sigil *= -1;
		if (*s == '+')
			sigil *= +1;
		s++;
	}

	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * sigil);
}

/**
 * count_characters - Count the coincidences of character in string.
 * @string: Pointer to str origen.
 * @character: String with  chars to be counted
 * Return: int of string or 0.
 */
int count_characters(char *string, char *character)
{
	int x = 0, counter = 0;

	for (; string[x]; x++)
	{
		if (string[x] == character[0])
			counter++;
	}
	return (counter);
}

