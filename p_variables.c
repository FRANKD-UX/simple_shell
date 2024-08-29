#include "shell.h"
/**
 * p_variables - expand variables
 * @data: a pointer to a struct of the program's data
 * Return: nothing, but sets errno.
 */
void p_variables(program_data *data)
{
	int x, y; /*Loop counters*/
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL) /* Check if input_line in 'data' is NULL, if so, return immediately*/
		return;
	buffer_p(line, data->input_line); /* Process the input_line and store the result in 'line'*/
	for (x = 0; line[x]; x++) /* Iterate through each character in 'line*/
		if (line[x] == '#') /* If a '#' character is found, truncate the string at this point*/
			line[x--] = '\0'; /* Replace '#' with null terminator and decrement 'x' to possibly handle consecutive '#'*/
		else if (line[x] == '$' && line[x + 1] == '?') /* Replace '$' with null terminator to end the current part of the string*/
		{
			line[x] = '\0';
			int_to_string(errno, expansion, 10); /* Append the error code string to the current 'line'*/
			buffer_ap(line, expansion); /* Append the remainder of the original input line starting from after "$?"*/
			buffer_p(line, data->input_line + x + 2);
		}
		else if (line[x] == '$' && line[x + 1] == '$')
		{
			line[x] = '\0';
			int_to_string(getpid(), expansion, 10); /* Convert the process ID (pid) to a string and store in 'expansion'*/
			buffer_p(line, expansion); /* Append the process ID string to the current 'line'*/
			buffer_p(line, data->input_line + x + 2); /* Append the remainder of the original input line starting from after "$$"*/
		}
		else if (line[x] == '$' && (line[x + 1] == ' ' || line[x + 1] == '\0'))
			continue;
		else if (line[x] == '$')
		{
			for (y = 1; line[x + y] && line[x + y] != ' '; y++)
				expansion[y - 1] = line[x + y];
			temp = getkey(expansion, data);
			line[x] = '\0', expansion[0] = '\0';
			buffer_p(expansion, line + x + y);
			temp ? buffer_p(line, temp) : 1;
			buffer_p(line, expansion);
		}
	if (!string_c(data->input_line, line, 0))
	{
		free(data->input_line);
		data->input_line = string_d(line);
	}
}
/**
 * Processes and expands aliases in the input line of 'data'.
 * This function takes the input line from 'data', processes it to check for any 
 * aliases, and replaces occurrences of aliases with their corresponding values. 
 * It then updates 'data->input_line' with the expanded result if any aliases were expanded.
 * @param data A pointer to a 'program_data' structure containing the input line to be processed.
 */
void p_alias(program_data *data)
{
	int x, y, was_expanded = 0;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;

	buffer_p(line, data->input_line);

	for (x = 0; line[x]; x++)
	{
		for (y = 0; line[x + y] && line[x + y] != ' '; y++)
			expansion[y] = line[x + y];
		expansion[y] = '\0';

		temp = get_a(data, expansion);
		if (temp)
		{
			expansion[0] = '\0';
			buffer_p(expansion, line + x + y);
			line[x] = '\0';
			buffer_p(line, temp);
			line[string_l(line)] = '\0';
			buffer_p(line, expansion);
			was_expanded = 1;
		}
		break;
	}
	if (was_expanded)
	{
		free(data->input_line);
		data->input_line = string_d(line);
	}
}

/**
 * buffer_add - append string at end of the buffer
 * @buffer: A pointer to the destination string where 'string_add' will be appended
 * @str_add: A pointer to the string that will be appended to 'buffer' * Return: The length of 'buffer' after the append operation..
 */
int buffer_p(char *buffer, char *string_add)
{
	int l, x;

	l = string_l(buffer);
	for (x = 0; str_add[x]; x++)
	{
		buffer[l + x] = str_add[x];
	}
	buffer[l + x] = '\0';
	return (l + x);
}
/*This code is by Frank Ndlovu and Nomcebo Mncina*/
