#include "shell.h"

/**
 * _print - writes a array of chars in the standar output
 * @string: pointer to the array of chars
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 * Authors: Frank Ndlovu and Nomcebo Mncina
 */

int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}
/**
 * _print1 - Writes an array of chars in the standard error
 * @string: Pointer to the array of chars
 * Return: The number of bytes written or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int _print1(char *string)
{
	return (write(STDERR_FILENO, string, str_length(string)));
}

/**
 * _print_error - Writes an array of chars in the standard error
 * @data: A pointer to the program's data'
 * @errorcode: Error code to print
 * Return: The number of bytes written or .
 * On error, -1 is returned, and errno is set appropriately.
 */

int _print_error(int errorcode, p_data *data)
{
	char n_as_string[10] = {'\0'};

	long_to_string((long) data->exec_counter, n_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_print1(data->program_name);
		_print1(": ");
		_print1(n_as_string);
		_print1(": ");
		_print1(data->tokens[0]);
		if (errorcode == 2)
			_print1(": Illegal Number Entered: ");
		else
			_print1(": Cannot Go Into It ");
		_print1(data->tokens[1]);
		_print1("\n");
	}
	else if (errorcode == 127)
	{
		_print1(data->program_name);
		_print1(": ");
		_print1(n_as_string);
		_print1(": ");
		_print1(data->command_name);
		_print1(": Not Found\n");
	}
	else if (errorcode == 126)
	{
		_print1(data->program_name);
		_print1(": ");
		_print1(n_as_string);
		_print1(": ");
		_print1(data->command_name);
		_print1(": Permission Denied\n");
	}
	return (0);
}

