#include "sshell.h"

/**
 * expand_variables - Expand variables
 * @data: A pointer to a structure of the program's data
 * Return: Nothing, but sets errno.
 * Authors: Frank Ndlovu and Nomcebo Mncina
 */

void expand_variables(p_data *data)
{
	int x, y;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;
	buffer_add(line, data->input_line);
	for (x = 0; line[x]; x++)
		if (line[x] == '#')
			line[x--] = '\0';
		else if (line[x] == '$' && line[x + 1] == '?')
		{
			line[x] = '\0';
			long_to_string(errno, expansion, 10);
			buffer_add(line, expansion);
			buffer_add(line, data->input_line + x + 2);
		}
		else if (line[x] == '$' && line[x + 1] == '$')
		{
			line[x] = '\0';
			long_to_string(getpid(), expansion, 10);
			buffer_add(line, expansion);
			buffer_add(line, data->input_line + x + 2);
		}
		else if (line[x] == '$' && (line[x + 1] == ' ' || line[x + 1] == '\0'))
			continue;
		else if (line[x] == '$')
		{
			for (y = 1; line[x + y] && line[x + y] != ' '; y++)
				expansion[y - 1] = line[x + y];
			temp = env_get_key(expansion, data);
			line[x] = '\0', expansion[0] = '\0';
			buffer_add(expansion, line + x + y);
			temp ? buffer_add(line, temp) : 1;
			buffer_add(line, expansion);
		}
	if (!str_compare(data->input_line, line, 0))
	{
		free(data->input_line);
		data->input_line = str_duplicate(line);
	}
}

/**
 * expand_alias - Expans aliases
 * @data: A pointer to a structure of the program's data
 * Return: Nothing, but sets errno.
 */

void expand_alias(p_data *data)
{
	int x, y, was_expanded = 0;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;

	buffer_add(line, data->input_line);

	for (x = 0; line[x]; x++)
	{
		for (y = 0; line[x + y] && line[x + y] != ' '; y++)
			expansion[y] = line[x + y];
		expansion[y] = '\0';

		temp = get_alias(data, expansion);
		if (temp)
		{
			expansion[0] = '\0';
			buffer_add(expansion, line + x + y);
			line[x] = '\0';
			buffer_add(line, temp);
			line[str_length(line)] = '\0';
			buffer_add(line, expansion);
			was_expanded = 1;
		}
		break;
	}
	if (was_expanded)
	{
		free(data->input_line);
		data->input_line = str_duplicate(line);
	}
}

/**
 * buffer_add - Append string at end of the buffer
 * @buffer: Buffer to be filled
 * @str_to_add: A string to be copied in the buffer
 * Return: nothing, but sets errno.
 */

int buffer_add(char *buffer, char *str_to_add)
{
	int length, x;

	length = str_length(buffer);
	for (x = 0; str_to_add[x]; x++)
	{
		buffer[length + x] = str_to_add[x];
	}
	buffer[length + x] = '\0';
	return (length + x);
}
