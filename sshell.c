#include "sshell.h"

/**
 * main - initialize the variables of the program
 * @argc: number of values received from the command line
 * @argv: values received from the command line
 * @env: number of values received from the command line
 * Return: zero on succes.
 * Authours: Frank Ndlovu and Nomcebo Mncina
 */

int main(int argc, char *argv[], char *env[])
{
	p_data data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	initialize_data(data, argc, argv, env);

	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		errno = 2;
		prompt = PROMPT_MSG;
	}
	errno = 0;
	sisifo(prompt, data);
	return (0);
}

/**
 * handle_ctrl_c - print the prompt in a new line
 * when the signal SIGINT (ctrl + c) is send to the program
 * @UNUSED: option of the prototype
 */

void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}

/**
 * initialize_data - initializes the structure with the info of the program
 * @data: Pointer to the structure of data
 * @argv: Array of arguments passed to the program execution
 * @env: Environment passed to the program execution
 * @argc: Number of values received from the command line
 */

void initialize_data(p_data *data, int argc, char *argv[], char **env)
{
	int x = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;
	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_printe(data->program_name);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[x]; x++)
		{
			data->env[x] = str_duplicate(env[x]);
		}
	}
	data->env[x] = NULL;
	env = data->env;

	data->alias_list = malloc(sizeof(char *) * 20);
	for (x = 0; x < 20; x++)
	{
		data->alias_list[x] = NULL;
	}
}
/**
 * sisifo - An infinite loop that shows the prompt
 * @prompt: Prompt to be printed
 * @data: An infinite loop that shows the prompt
 */

void sisifo(char *prompt, p_data *data)
{
	int error_code = 0, string_len = 0;

	while (++(data->exec_counter))
	{
		_print(prompt);
		error_code = string_len = _getline(data);

		if (error_code == EOF)
		{
			free_all_data(data);
			exit(errno);
		}
		if (string_len >= 1)
		{
			expand_alias(data);
			expand_variables(data);
			tokenize(data);
			if (data->tokens[0])
			{
				error_code = execute(data);
				if (error_code != 0)
					_print_error(error_code, data);
			}
			free_recurrent_data(data);
		}
	}
}
