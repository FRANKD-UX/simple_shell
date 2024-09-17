#include "shell.h"

/**
* _getline - Reads one line from the prompt.
* @data: Structure for the program's data
* Return: Reading counting bytes.
* Authors: Frank Ndlovu and Nomcebo Mncina
*/

int _getline(p_data *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t bytes_read, x = 0;

	if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) ||
		(array_operators[0] == '|' && errno == 0))
	{
		for (x = 0; array_commands[x]; x++)
		{
			free(array_commands[x]);
			array_commands[x] = NULL;
		}

		bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);

		x = 0;
		do {
			array_commands[x] = str_duplicate(_strtok(x ? NULL : buff, "\n;"));
			x = check_logic_ops(array_commands, x, array_operators);
		} while (array_commands[x++]);
	}

	data->input_line = array_commands[0];
	for (x = 0; array_commands[x]; x++)
	{
		array_commands[x] = array_commands[x + 1];
		array_operators[x] = array_operators[x + 1];
	}

	return (str_length(data->input_line));
}

/**
* check_logic_ops - Checks and split for operators
* @array_commands: Array of the commands.
* @x: Index in the array of commands to be checked
* @array_operators: Array of the logical operators for each previous command
* Return: Index of the last command in the array_commands.
*/

int check_logic_ops(char *array_commands[], int x, char array_operators[])
{
	char *temp = NULL;
	int y;

	for (y = 0; array_commands[x] != NULL  && array_commands[x][y]; y++)
	{
		if (array_commands[x][y] == '&' && array_commands[x][y + 1] == '&')
		{
			temp = array_commands[x];
			array_commands[x][y] = '\0';
			array_commands[x] = str_duplicate(array_commands[x]);
			array_commands[x + 1] = str_duplicate(temp + y + 2);
			x++;
			array_operators[x] = '&';
			free(temp);
			y = 0;
		}
		if (array_commands[x][y] == '|' && array_commands[x][y + 1] == '|')
		{
			temp = array_commands[x];
			array_commands[x][y] = '\0';
			array_commands[x] = str_duplicate(array_commands[x]);
			array_commands[x + 1] = str_duplicate(temp + y + 2);
			x++;
			array_operators[x] = '|';
			free(temp);
			y = 0;
		}
	}
	return (x);
}
