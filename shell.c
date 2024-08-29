#include "shell.h"
/*main- program entry point, initializes variables, controls flow*/
int main(int argc, char *argv[], char *env[]) /* initialize the variables of the program */
{
	program_data data_structure = {NULL}, *data = &data_structure;
	char *prompt = "";

	init_data(data, argc, argv, env);

	signal(SIGINT, cnrl); /*sends program*/

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		errno = 2;
		prompt = MSG_PROMPT;
	}
	errno = 0;
	inf_loop(prompt, data);
	return (0);
}

void cnrl(int opr UNUSED)/* print prompt in a new line | prototype option*/
{
	print1("\n");
	print1(MSG_PROMPT);
}
void init_data (program_data *data, int argc, char *argv[], char **env) /*structure with program info*/
{
	int x = 0;
	data->input_line = NULL; /*pointer of structure of data*/
	data->program_name = argv[0];
	data->ex_count = 0;
	data->command_name = NULL;
		
	if (argc == 1) /*values number received from the command line*/
		data->file_descr = STDIN_FILENO; /* file descriptor to be read*/
	else
	{
		data->file_descr = open(argv[1], O_RDONLY);
		if (data->file_descr == -1)
		{
			print2(data->program_name);
			print2(": 0: Can't open ");
			print2(argv[1]); /*array of argument*/
			print2("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 60);
	if (env) /*environment for program execution*/
	{
		for (; env[x]; x++)
		{
			data->env[x] = string_d(env[x]);
		}
	}
	data->env[x] = NULL;
	env = data->env;

	data->alias_list= malloc(sizeof(char *) * 25);
	for (x = 0; x < 20; x++)
	{
		data->alias_list[x] = NULL;
	}
}
void inf_loop(char *prompt, program_data *data) /* infinite loop that shows the prompt */
{
	int error_code = 0, string_len = 0;

	while (++(data->ex_count))
	{
		print1(prompt); /* prompt to be printed*/
		error_code = string_len = fetch(data);

		if (error_code == EOF)
		{
			free_data(data);
			exit(errno);		}
		if (string_len >= 1)
		{
			p_alias(data);
			p_variables(data);

			tokenize(data);
			if (data->tokens[0])
			{ 
				error_code = change(data);
				if (error_code != 0)
					printErr(error_code, data);
			}
			recurrent_data(data);
		}
	}
}
/*Code by Frank Ndlovu and Nomcebo Mncina*/
