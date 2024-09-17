#include "shell.h"

/**
 * tokenize – Function to separate the string using a designed delimiter
 * @data: a pointer to the program's data
 * Return: an array of the different parts of the string
 * Authors: Frank Ndlovu and Nomcebo Mncina
 */

void tokenize(p_data *data)
{
	char *delimiter = " \t";
	int x, y, counter = 2, length;

	length = str_length(data->input_line);
	if (length)
	{
		if (data->input_line[length - 1] == '\n')
			data->input_line[length - 1] = '\0';
	}

	for (x = 0; data->input_line[x]; x++)
	{
		for (y = 0; delimiter[y]; y++)
		{
			if (data->input_line[x] == delimiter[y])
				counter++;
		}
	}

	data->tokens = malloc(counter * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}
	x = 0;
	data->tokens[x] = str_duplicate(_strtok(data->input_line, delimiter));
	data->command_name = str_duplicate(data->tokens[0]);
	while (data->tokens[x++])
	{
		data->tokens[x] = str_duplicate(_strtok(NULL, delimiter));
	}
}

