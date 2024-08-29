#include "shell.h"
/** 
* Writes a string to the standard output (stdout). 
* This function prints the specified string to the standard output using the 
* `write` system call. The length of the string is determined by `string_l()`, 
* which should return the number of characters in the string excluding the 
* null terminator. 
* @param string A pointer to the null-terminated string to be printed. 
* @return Returns the number of bytes written on success, or -1 on failure. 
*/
int print2(char *string)
{
	return (write(STDOUT_FILENO, string, string_l(string))); /* Use the 'write' system call to print the string to standard output*/
}
/** 
* Writes a string to the standard error (stderr). 
* This function prints the specified string to the standard error using the 
* `write` system call. The length of the string is determined by `string_l()`, 
* which should return the number of characters in the string excluding the 
* null terminator. 
* @param string A pointer to the null-terminated string to be printed. 
* @return Returns the number of bytes written on success, or -1 on failure. 
*/
int printErr(char *string)
{
	return (write(STDERR_FILENO, string, string_l(string))); /* Use the 'write' system call to print the string to standard error*/
}
/** 
* Prints error messages to standard output based on the provided error code. 
* This function generates and prints an error message formatted with information 
* about the error code, the program name, the command name, and additional details. 
* The message is formatted differently depending on the specific error code. 
* @param errorcode The error code that determines the format and content of the error message. 
* @param data A pointer to a 'program_data' structure containing relevant information for error reporting. 
* @return Returns 0 on success. 
*/
int printErr(int errorcode, program_data *data)
{
	char n_as_string[10] = {'\0'};

	int_to_string((long) data->ex_count, n_as_string, 10); /* Convert the execution count to a string*/

	if (errorcode == 2 || errorcode == 3) /* Print error message based on the provided error code*/
	{
		print2(data->program_name); /* Program name*/
		print2(": ");
		print2(n_as_string); /* Execution count*/
		print2(": ");
		print2(data->tokens[0]); /* Command or file*/
		if (errorcode == 2)
			print2(": You are not allowed to enter this number: ");
		else
		print2(": Unable to enter directory ");
		print2(data->tokens[1]); /* Additional information (e.g., directory name)*/
		print2("\n");
	}
	else if (errorcode == 127) /* Print error message for error code 127 (command not found)*/
	{
		print2(data->program_name); /* Program name*/
		print2(": ");
		print2(n_as_string); /* Execution count*/
		print2(": ");
		print2(data->command_name);
		print2(": NONE\n"); /* Error message*/
	}
	else if (errorcode == 126)/* Print error message for error code 126 (command cannot be executed)*/
	{
		print2(data->program_name); /* Program name*/
		print2(": ");
		print2(n_as_string); /* Execution count*/
		print2(": ");
		print2(data->command_name);
		print(": You do not have access to this\n"); /* Error message*/
	}
	return (0); /* Return 0 to indicate successful completion*/
}
/*This code was made by Frank Ndlovu and Nomcebo Mncina*/
