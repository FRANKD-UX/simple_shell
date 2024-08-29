#include "shell.h"
/**
 * int_to_string - converts a number to a string
 * Converts an integer to a string representation in the
 * specified base. This function converts a given integer
 * into a string representation based on the specified base.
 * It supports bases from 2 to 16 (binary to hexadecimal). The
 * functionhandles negative numbers and zero appropriately. The
 * resulting string is null-terminatedand stored in the provided
 * buffer. The buffer should be large enough to hold the result.
 * @num: The integer to be converted.
 * @string: A pointer to the buffer where the resulting string will
 * be stored.
 * @base: The base for the conversion, which must be between 2 and 16
 * (inclusive).
 * base 10 is decimal, and base 16 is hexadecimal.
 */
void int_to_string(long num, char *string, int base)
{
int index = 0;/*Index for the string buffer*/
int inN = 0;/*Flag to indicate if the number is negative*/
long con = num;/*Copy of the number to be processed*/
char letters[] = "0123456789abcdef";

if (con == 0)
	string[index++] = '0';

if (con < 0)
{
	inN = 1;
	con = -con;/*Make the number positive for processing*/
}

while (con)
{
	string[index++] = letters[con % base];
	con /= base; /*Move to the next digit*/
}

if (inN)
	string[index++] = '-';
	string[index] = '\0';
	string_r(string);
}
/**
 * string_to_num - Converts a string to an integer.
 * This function parses a string to convert it into an integer.
 * Handles optional leading signs (`+` or `-`) and skips any
 * non-numeric characters before the numeric part of the string.
 * The function stops parsing when it encounters a non-numeric
 * character after the number.
 * @s: A pointer to the null-terminated string to be converted.
 * @return: The integer value represented by the string.
 */
int string_to_num(char *s)
{
int sign = 1;
unsigned int num = 0;

    /*Analyze and handle the sign of the number*/
	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;/*Set sign to negative*/
		else if (*s == '+')
			sign *= +1;/*Set sign to positive*/
		s++;/*Move to the next character*/
	}

while ('0' <= *s && *s <= '9' && *s != '\0')
{
	num = (num * 10) + (*s - '0');/*Build the number*/
	s++;/*Move to the next character*/
}

return (num * sign);/*Return the num with right sign*/
}

/**
 * count - Counts the occurrences of a specific character
 * in a string.This function iterates through a
 * null-terminated string and counts how many times a
 * specified character appears in the string. The
 * character to be counted is provided
 * as a single-character string.
 * @string: A pointer to the null-terminated string
 * to be searched.
 * @character: A pointer to a single-character string
 * representing the character to count.
 * @return: The number of times the specified character appears
 */
int count(char *string, char *character)
{
int x = 0;/*Index for iterating through the string*/
int counter = 0;/*Counter for the occurrences of the char*/

if (character == NULL || character[1] != '\0')
	return (0);

for (; string[x]; x++)
{
	if (string[x] == character[0])
	counter++;/*Increment the counter*/
}

	return (counter);/*Return the total count of occurrences*/
}
/*This is a code by  Frank Ndlovu and Nomcebo Mncina*/
