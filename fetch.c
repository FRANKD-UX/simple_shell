#include "shell.h"

/**
* fetch - function to read one line from the prompt.
* @data: the program's data’s structure
* @return – reads the counting bytes.
*/
int fetch(program_data *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	ssize_t br, x = 0;
	static char a_op[10] = {'\0'};
	static char *a_com[10] = {NULL};

		if (!a_com[0] || (a_op[0] == '&' && errno != 0) ||

		(a_op[0] == '|' && errno == 0))
	{
		for (x = 0; a_com[x]; x++) /*allocated memory freed */
		{
			free(a_com[x]);
			a_com[x] = NULL;
		}

	br = read(data->file_descr, &buff, BUFFER_SIZE - 1);

		if (br == 0)
			return (-1);

		/* split lines for \n or ; */
		x = 0;
		do {
			a_com[x] = string_d(_strtok(x ? NULL : buff, "\n;"));
			x = check(a_com, x, a_op);
		} while (a_com[x++]);
	}

	data->input_line = a_com[0];
	/*gets next command and removes it for the array*/
	for (x = 0; a_com[x]; x++)
	{
		a_com[x] = a_com[x + 1];
		a_op[x] = a_op[x + 1];
	}

	return (string_l(data->input_line));
}


/**
* @a_com: array of the commands.
* @x: index in the a_com to be checked
* @a_op: array of the logical operators
* check – used to check and split &&, for and || operators
* return - last command index in the a_coms.
*/
int check(char *a_com[], int x, char a_op[])
{
	int y;
	char *temp = NULL;

	for (y = 0; a_com[x] != NULL  && a_com[x][y]; y++)
	{
		if (a_com[x][y] == '&' && a_com[x][y + 1] == '&')
		{
			temp = a_com[x];
			a_com[x][y] = '\0';
			a_com[x] = string_d(a_com[x]);
			a_com[x + 1] = string_d(temp + y + 2);
			x++;
			a_op[x] = '&';
			free(temp);
			y = 0;
		}
		if (a_com[x][y] == '|' && a_com[x][y + 1] == '|')
		{
			temp = a_com[x];
			a_com[x][y] = '\0';
			a_com[x] = string_d(a_com[x]);
			a_com[x + 1] = string_d(temp + y + 2);
			x++;
			a_op[x] = '|';
			free(temp);
			y = 0;
		}
	}
	return (x);
}
/*This code was written Frank Ndlovu and Nomcebo Mncina*/
