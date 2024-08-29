#include "shell.h"

<<<<<<< HEAD
/**
 * print_env_vars - Prints the environment variables.
 * @data: A pointer to a 'program_data' structure containing the 
 * command tokens and environment data.
 */
void print_env_vars(program_data *data)
{
	printEnv(data);
}

/**
 * handle_variable_assignment - Handles setting an environment variable.
 * @data: A pointer to a 'program_data' structure containing the 
 * command tokens and environment data.
 * @cpname: A buffer to store the variable name.
 * @x: The index in the tokens array where the '=' character was found.
 *
 * Return: Returns 0 on success.
 */
int handle_variable_assignment(program_data *data, char *cpname, int x)
{
	char *var_copy = string_d(get_key(cpname, data));

	if (var_copy != NULL)
	{
		set_key(cpname, data->tokens[1] + x + 1, data);
	}

	printEnv(data);

	if (get_key(cpname, data) == NULL)
	{
		print1(data->tokens[1]);
		print1("\n");
	}
	else
	{
		set_key(cpname, var_copy, data);
		free(var_copy);
	}
	return (0);
}

/**
 * builtin_env - Handles the built-in 'env' command functionality.
 * @data: A pointer to a 'program_data' structure containing the 
 * command tokens and environment data.
 *
 * This function processes the 'env' command to either print the current 
 * environment variables or set an environment variable if a variable 
 * assignment is provided.
 *
 * Return: Returns 0 on successful execution.
 */
int builtin_env(program_data *data)
{
	int x;
	char cpname[50] = {'\0'};

	if (data->tokens[1] == NULL)
	{
		print_env_vars(data);
	}
	else
	{
		for (x = 0; data->tokens[1][x]; x++)
		{
			if (data->tokens[1][x] == '=')
			{
				return (handle_variable_assignment(data, cpname, x));
			}
			cpname[x] = data->tokens[1][x];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
=======
/**
 * builtin_env - shows the environment where the shell runs
 * Handles the built-in 'env' command functionality.
 * This function processes the 'env' command to either
 * print the current environment
 * variables or set an environment variable if a
 * variable assignment is provided.
 * @data: A pointer to a 'program_data' structure
 * containing the command tokens and environment data.
 * @return: Returns 0 on successful execution.
 */
int builtin_env(program_data *data)
{
int x;
char cpname[50] = {'\0'};
char *var_copy = NULL;

if (data->tokens[1] == NULL)
{
	printEnv(data);
}
else
{
for (x = 0; data->tokens[1][x]; x++)
{
	if (data->tokens[1][x] == '=')
	{
	var_copy = string_d(get_key(cpname, data));

	if (var_copy != NULL)
	{
		set_key(cpname, data->tokens[1] + x + 1, data);
	}

	printEnv(data);

	if (get_key(cpname, data) == NULL)
	{
		print1(data->tokens[1]);
		print1("\n");
	}
	else
	{
		set_key(cpname, var_copy, data};
		free(var_copy);
	}
	return (0);
	}
	cpname[x] = data->tokens[1][x];
	}
	errno = 2;
	perror(data->command_name);
	errno = 127;
>>>>>>> 52f939a19aae8c03c263fbe2834f5f21e4bd17ec
	}
	return (0);
}

/**
<<<<<<< HEAD
 * builtin_set_env - Handles the built-in 'setenv' command functionality.
 * @data: A pointer to a 'program_data' structure containing the command 
 * tokens and environment data.
 *
 * This function sets an environment variable to a specified value. 
 * It expects exactly two arguments: the name of the environment variable 
 * and its value. If the number of arguments is incorrect or too many 
 * arguments are provided, the function sets an appropriate error and 
 * returns a specific error code.
 *
 * Return: Returns 0 on success, or a non-zero error code on failure.
 */
int builtin_set_env(program_data *data)
{
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
	{
		return (0);
	}

	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	set_key(data->tokens[1], data->tokens[2], data);
=======
 * builtin_set_env - handles the built-in 'setenv' command functionality.
 * This function sets an environment variable to a
 * pecified value. It expects exactly two arguments:
 * the name of the environment variable and its value.
 * If the number of arguments is incorrect or too many
 * arguments are provided, the function sets an appropriate
 * error and returns a specific error code.
 * @data: A pointer to a 'program_data' structure containing
 * the command to and environment data.
 * @return: Returns 0 on success, or non-zero errorcode onfailure.
 */
int builtin_set_env(program_data *data)
{
if (data->tokens[1] == NULL || data->tokens[2] == NULL)
	/*Check if the required number of arguments is provided*/
{
	return (0);
}

if (data->tokens[3] != NULL)
	    /*Check if there are more than the allowed number of arguments*/
{
	errno = E2BIG;
	/*Set errno to E2BIG (argument list too long) to indicate an error*/
	perror(data->command_name);
	/*Print the error message associated with errno*/
	return (5);
	/*Return error code 5 indicating too many arguments*/
}

	set_key(data->tokens[1], data->tokens[2], data);
    /*Set the environment variable using the provided name and value*/
>>>>>>> 52f939a19aae8c03c263fbe2834f5f21e4bd17ec

	return (0);
}

/**
<<<<<<< HEAD
 * builtin_unset_env - Handles the built-in 'unsetenv' command functionality.
 * @data: A pointer to a 'program_data' structure containing the 
 * command tokens and environment data.
 *
 * This function removes an environment variable specified by the argument. 
 * It expects exactly one argument: the name of the environment variable 
 * to be removed. If no arguments or too many arguments are provided, the 
 * function sets an appropriate error and returns a specific error code.
 *
 * Return: Returns 0 on success, or a non-zero error code on failure.
=======
 * builtin_unset_env - handles the built-in 'unsetenv' command functionality.
 * This function removes an environment variable
 * specified by the argument.
 * It expects exactly one argument: the name of the environment
 * variable to be removed.
 * If no arguments or too many arguments are provided,
 * the function sets an appropriate error and returns a
 * specific error code.
 * @data: A pointer to a 'program_data' structure containing
 * the command tokens and environment data.
 * @return Returns 0 on success, or a non-zero error code on failure.
>>>>>>> 52f939a19aae8c03c263fbe2834f5f21e4bd17ec
 */
int builtin_unset_env(program_data *data)
{
	if (data->tokens[1] == NULL)
<<<<<<< HEAD
	{
		return (0);
	}

	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	deletekey(data->tokens[1], data);
=======
	/*Check if the required argument (variable name) is provided*/
	{
	return (0);
	/*If no argument is provided, return 0 (no action taken)*/
	}

	if (data->tokens[2] != NULL)
	/*Check if there are more than the allowed number of arguments*/
	{
	errno = E2BIG;
	/*Set errno to E2BIG (argument list too long) to indicate an error*/
	perror(data->command_name);
	/*Print the error message associated with errno*/
	return (5);
	/*Return error code 5 indicating too many arguments*/
	}

	deletekey(data->tokens[1], data);
    /*Remove the environment variable specified by the first argument*/
>>>>>>> 52f939a19aae8c03c263fbe2834f5f21e4bd17ec

	return (0);
}

