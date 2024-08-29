
#include "shell.h"
/** 
* Computes the length of a null-terminated string. 
* This function calculates the length of a string by iterating through the characters 
* until it reaches the null terminator. It returns the number of characters in the string 
* excluding the null terminator. If the input string is NULL, it returns 0.  
* @param string A pointer to a null-terminated string whose length is to be determined. 
* @return The length of the string. Returns 0 if the input string is NULL. 
*/
{
	int l = 0;

	if (string == NULL)
		return (0);

	while (string[l++] != '\0')
	{
	}
	return (--l);
}
/** 
* Duplicates a string by allocating new memory and copying the content. 
* This function creates a new string that is a duplicate of the provided input string. 
* It allocates memory for the new string, including space for the null terminator, 
* and then copies the content of the input string into the newly allocated memory. 
* If the input string is NULL, the function returns NULL. If memory allocation fails, 
* it sets the errno to ENOMEM and prints an error message. 
* @param string A pointer to the null-terminated string to be duplicated. 
* @return A pointer to the newly allocated string that is a duplicate of the input string, 
* or NULL if the input string is NULL or if memory allocation fails. 
*/
char *string_d(char *string)
{
	char *result;
	int l, x;

	if (string == NULL)
		return (NULL);

	l = string_l(string) + 1;

	result = malloc(sizeof(char) * l);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (x = 0; x < l ; x++)
	{
		result[x] = string[x];
	}

	return (result);
}

/**
 * Compares two strings for equality with an optional length constraint.
 * 
 * This function compares two strings and determines if they are equal based on
 * the given constraints. It can compare the entire strings or only up to a specified
 * number of characters. It handles the case where one or both strings are NULL.
 * 
 * @param string1 A pointer to the first string to be compared.
 * @param string2 A pointer to the second string to be compared.
 * @param num The number of characters to compare. If num is 0, the function compares
 * the entire strings. If num is greater than 0, it compares only up to 
 *num characters.
 * @return 1 if the strings are equal based on the specified constraints, 0 otherwise.
 */
int string_c(char *string1, char *string2, int num)
{
    int i;

    // Handle cases where both strings are NULL
    if (string1 == NULL && string2 == NULL)
        return (1);

    // Handle cases where one of the strings is NULL
    if (string1 == NULL || string2 == NULL)
        return (0);

    // Compare entire strings if num is 0 (infinite length)
    if (num == 0)
    {
        // Check if lengths are equal
        if (string_l(string1) != string_l(string2))
            return (0);

        // Compare characters one by one
        for (i = 0; string1[i]; i++)
        {
            if (string1[i] != string2[i])
                return (0);
        }
        return (1);
    }
    else
    {
        // Compare up to 'num' characters
        for (i = 0; i < num; i++)
        {
            // Return 0 if characters differ or if one string ends before 'num' characters
            if (string1[i] != string2[i] || string1[i] == '\0' || string2[i] == '\0')
                return (0);
        }
        return (1);
    }
}
/** * Concatenates two strings and returns a new string. 
* This function creates a new string that is the concatenation of two input strings. 
* If either input string is NULL, it is treated as an empty string. The function 
* allocates sufficient memory to hold the concatenated result, including the null terminator. 
* If memory allocation fails, it sets errno to ENOMEM and prints an error message. 
* @param string1 A pointer to the first string to be concatenated. If NULL, it is treated as an empty string. 
* @param string2 A pointer to the second string to be concatenated. If NULL, it is treated as an empty string. 
* @return A pointer to the newly allocated string containing the concatenated result, or NULL if memory allocation fails. 
*/
char *string_cc(char *string1, char *string2)
{
	char *result;
	int length1 = 0, length2 = 0;

	if (string1 == NULL)
		string1 = "";
	length1 = string_l(string1);

	if (string2 == NULL)
		string2 = "";
	length2 = string_l(string2);

	result = malloc(sizeof(char) * (length1 + length2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	/* copy string1 */
	for (length1 = 0; string1[length1] != '\0'; length1++)
		result[length1] = string1[length1];
	free(string1);

	/* copy string2 */
	for (length2 = 0; string2[length2] != '\0'; length2++)
	{
		result[length1] = string2[length2];
		length1++;
	}

	result[length1] = '\0';
	return (result);
}

/**
 * Reverses a string in place.
 * 
 * This function reverses the characters of a given null-terminated string by
 * swapping characters from the beginning and the end of the string, moving towards
 * the center. The reversal is done in place, so the original string is modified.
 * @param string A pointer to the null-terminated string to be reversed. The string must
 * be mutable and properly null-terminated.
 */
void string_r(char *string)
{
    int x = 0; // Index for the start of the string
    int l = string_l(string) - 1; // Index for the end of the string
    char hold;// Temporary variable for swapping characters

    // Loop to swap characters from both ends towards the center
    while (x < l)
    {
        hold = string[x]; // Store the current character at the start
        string[x++] = string[l]; // Replace the start character with the end character
        string[l--] = hold;// Replace the end character with the stored start character
    }
}

/*This code is by Frank Ndlovu and Nomcebo Mncina*/
