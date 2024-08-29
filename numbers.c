
#include "shell.h"
/**
 * Converts an integer to a string representation in the specified base. 
 * This function converts a given integer into a string representation based on the
 * specified base. It supports bases from 2 to 16 (binary to hexadecimal). The function
 * handles negative numbers and zero appropriately. The resulting string is null-terminated
 * and stored in the provided buffer. The buffer should be large enough to hold the result.
 * 
 * @param num The integer to be converted.
 * @param string A pointer to the buffer where the resulting string will be stored.
 * @param base The base for the conversion, which must be between 2 and 16 (inclusive).
 * Base 10 is decimal, and base 16 is hexadecimal.
 */
void int_to_string(long num, char *string, int base)
{
    int index = 0;// Index for the string buffer
    int inN = 0;// Flag to indicate if the number is negative
    long con = num;// Copy of the number to be processed
    char letters[] = "0123456789abcdef"; // Characters used for base conversion

    // Handle the case where the number is zero
    if (con == 0)
        string[index++] = '0';

    // Check if the number is negative
    if (con < 0)
    {
        inN = 1;
        con = -con; // Make the number positive for processing
    }

    // Convert the number to the specified base
    while (con)
    {
        string[index++] = letters[con % base]; // Get the character for the current digit
        con /= base; // Move to the next digit
    }

    // Add the negative sign if the number was negative
    if (inN)
        string[index++] = '-';

    // Null-terminate the string
    string[index] = '\0';

    // Reverse the string to get the correct order
    string_r(string);
}
/**
 * Converts a string to an integer.
 * This function parses a string to convert it into an integer. It handles optional 
 * leading signs (`+` or `-`) and skips any non-numeric characters before the numeric 
 * part of the string. The function stops parsing when it encounters a non-numeric 
 * character after the number.
 * @param s A pointer to the null-terminated string to be converted.
 * @return The integer value represented by the string. Returns 0 if the string does 
 * not contain any numeric characters.
 */
int string_to_num(char *s)
{
    int sign = 1; // Variable to store the sign of the number (1 for positive, -1 for negative)
    unsigned int num = 0; // Variable to store the resulting number

    // Analyze and handle the sign of the number
    while (!('0' <= *s && *s <= '9') && *s != '\0')
    {
        if (*s == '-')
            sign *= -1;// Set sign to negative
        else if (*s == '+')
            sign *= +1;// Set sign to positive (default behavior)
        s++;// Move to the next character
    }

    //  Extract the number from the string
    while ('0' <= *s && *s <= '9' && *s != '\0')
    {
        num = (num * 10) + (*s - '0'); // Build the number by adding each digit
        s++;// Move to the next character
    }

    return (num * sign); // Return the number with the appropriate sign
}

/**
 * Counts the occurrences of a specific character in a string.
 * This function iterates through a null-terminated string and counts how many times
 * a specified character appears in the string. The character to be counted is provided
 * as a single-character string.
 * @param string A pointer to the null-terminated string to be searched.
 * @param character A pointer to a single-character string representing the character to count.
 * @return The number of times the specified character appears in the string. Returns 0 if 
 *  the character is not found or if the input is invalid.
 */
int count(char *string, char *character)
{
    int x = 0; // Index for iterating through the string
    int counter = 0; // Counter for the occurrences of the character

    // Validate that 'character' is a single-character string
    if (character == NULL || character[1] != '\0')
        return 0;

    // Iterate through the string
    for (; string[x]; x++)
    {
        // Check if the current character matches the target character
        if (string[x] == character[0])
            counter++;// Increment the counter
    }

    return counter;// Return the total count of occurrences
}
/*This is a code by  Frank Ndlovu and Nomcebo Mncina*/
