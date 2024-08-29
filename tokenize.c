#include "shell.h"
/**
 * tokenize - this function separate the string using a designed delimiter
 * @data: a pointer to the program's data
 * Return: an array of the different parts of the string
 */
void tokenize(program_data *data) /*describes function’s purpose*/
{
	char *d = " \t";
	int x, y, counter = 2, l;

	l = string_l(data->input_line);
	/* compute the l of the input_line and assigns to variable ‘l’*/
	if (l)
	{
		if (data->input_line[l - 1] == '\n')
			data->input_line[l - 1] = '\0';
	}

	for (x = 0; data->input_line[x]; x++)
	{
		for (y = 0; d[y]; y++)
		{
			if (data->input_line[x] == d[y])
				counter++;
		}
	}

	data->tokens = malloc(counter * sizeof(char *));
	/*used to allocate memory dynamically for an array of pointers to ‘char’*/
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}
	x = 0;
	data->tokens[x] = string_d(_strtok(data->input_line, d));
	data->command_name = string_d(data->tokens[0]);
	while (data->tokens[x++])
	{
		data->tokens[x] = string_d(_strtok(NULL, d));
		/* tokenize segment of input string and store the result*/
	}
}
/*This code is by Frank Ndlovu and Nomcebo Mncina*/
