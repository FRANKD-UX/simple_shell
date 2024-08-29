#include "shell.h"
/**
 * Handles the built-in 'env' command functionality.
 * This function processes the 'env' command to either print the current environment variables
 * or set an environment variable if a variable assignment is provided. It uses the 'data'
 * structure to access the tokens and environment data.
 * @param data A pointer to a 'program_data' structure containing the command tokens and environment data.
 * @return Returns 0 on successful execution.
 */
int builtin_env(program_data *data)
{
	int x;
	char cpname[50] = {'\0'}; /*Buffer to store the variable name (max length 49 characters + null terminator)*/
	char *var_copy = NULL; /*Pointer to temporarily hold the value of an environment variable */

	if (data->tokens[1] == NULL) /*Check if no additional arguments are provided*/
		printEnv(data); /*Print all environment variables*/
	else
	{
		for (x = 0; data->tokens[1][x]; x++)  /*Iterate through characters in the argument to find '=' indicating a variable assignment*/
		{
			if (data->tokens[1][x] == '=')
			{
				var_copy = string_d(get_key(cpname, data)); /*Copy the current value of the variable*/
				if (var_copy != NULL) /*Set the new value for the environment variable*/
					set_key(cpname, data->tokens[1] + x + 1, data);

				printEnv(data); /*Print all environment variables to show the updated state*/
				if (get_key(cpname, data) == NULL) /*Check if the environment variable was successfully updated*/
				{
					print1(data->tokens[1]); /*Print an error message if the variable could not be set*/
					print1("\n");
				}
				else
				{
					set_key(cpname, var_copy, data); /*Restore the original value of the environment variable*/
					free(var_copy); /*Free the memory allocated for 'var_copy'*/
				}
				return (0);
			}
			cpname[x] = data->tokens[1][x]; /*Build the variable name*/
		}
		errno = 2; /*andle the case where '=' is not found in the argument*/
		perror(data->command_name); /*Print an error message indicating invalid syntax*/
		errno = 127; /*Set errno to command not found error code*/
	}
	return (0);
}
/**
 * Handles the built-in 'setenv' command functionality.
 * This function sets an environment variable to a specified value. It expects 
 * exactly two arguments: the name of the environment variable and its value. 
 * If the number of arguments is incorrect or too many arguments are provided, 
 * the function sets an appropriate error and returns a specific error code.
 * @param data A pointer to a 'program_data' structure containing the command tokens and environment data.
 * @return Returns 0 on success, or a non-zero error code on failure.
 */
int builtin_set_env(program_data *data)
{
	if (data->tokens[1] == NULL || data->tokens[2] == NULL) /*Check if the required number of arguments is provided*/
		return (0);
	if (data->tokens[3] != NULL)/* Check if there are more than the allowed number of arguments*/
	{
		errno = E2BIG; /* Set errno to E2BIG (argument list too long) to indicate an error*/
		perror(data->command_name); /* Print the error message associated with errno*/
		return (5); /* Return error code 5 indicating too many arguments*/
	}

	set_key(data->tokens[1], data->tokens[2], data); / Set the environment variable using the provided name and value**/

	return (0);
}
/** 
* Handles the built-in 'unsetenv' command functionality. 
* This function removes an environment variable specified by the argument. 
* It expects exactly one argument: the name of the environment variable to be removed. 
* If no arguments or too many arguments are provided, the function sets an appropriate error 
* and returns a specific error code.  
* @param data A pointer to a 'program_data' structure containing the command tokens and environment data. 
* @return Returns 0 on success, or a non-zero error code on failure. 
*/
int builtin_unset_env(program_data *data)
{
	if (data->tokens[1] == NULL) /* Check if the required argument (variable name) is provided*/
		return (0); /* If no argument is provided, return 0 (no action taken)*/	
	if (data->tokens[2] != NULL) /* Check if there are more than the allowed number of arguments*/
	{
		errno = E2BIG; /* Set errno to E2BIG (argument list too long) to indicate an error*/
		perror(data->command_name); /* Print the error message associated with errno*/
		return (5); /* Return error code 5 indicating too many arguments*/
	}
	deletekey(data->tokens[1], data); /* Remove the environment variable specified by the first argument*/

	return (0);
}
/*This code is by Frank Ndlovu and Nomcebo Mncina*/
