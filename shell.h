#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "macros.h"

/**
 * Authors: Frank Ndlovu and Nomcebo Mncina
 * struct info- Structure for the program's data
 * @program_name: The name of the executable
 * @input_line: Pointer to the input read for _getline function
 * @command_name: Pointer to the first command typed by the user
* @file_descriptor: File descriptor to input commands
 * @tokens: Pointer to array of tokenized input
 * @env: Copy of the environment
 * @alias_list: Array of pointers with aliases.
 * @exec_counter: The number of executed commands
*/
typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} p_data;

/**
 * struct builtins - struct for the builtins
 * @builtin: the name of the builtin
 * @function: the associated function to be called for each builtin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(p_data *data);
} builtins;

void initialize_data(p_data *data, int arc, char *argv[], char **env);
void sisifo(char *prompt, p_data *data);
void handle_ctrl_c(int opr UNUSED);



/*======== alias_m.c ========*/
int print_alias(p_data *data, char *alias);
char *get_alias(p_data *data, char *alias);
int set_alias(char *alias_string, p_data *data);

/* Getline*/
int _getline(p_data *data);
int check_logic_ops(char *array_commands[], int x, char array_operators[]);

/* expansions */
void expand_variables(p_data *data);
void expand_alias(p_data *data);
int buffer_add(char *buffer, char *str_to_add);

/*strtok.c */
void tokenize(p_data *data);
char *_strtok(char *line, char *delim);

/* exec.c */
int execute(p_data *data);

/*builtins_l.c*/
int builtins_list(p_data *data);

/* find_path.c */
char **tokenize_path(p_data *data);
int find_program(p_data *data);

/* helpers_f.c */
void free_array_of_pointers(char **directories);
void free_recurrent_data(p_data *data);
void free_data(p_data *data);

/* builtins_m.c */

int builtin_exit(p_data *data);
int builtin_cd(p_data *data);
int set_work_directory(p_data *data, char *new_dir);
int builtin_help(p_data *data);
int builtin_alias(p_data *data);

/* builtins_e.c */
int builtin_env(p_data *data);
int builtin_set_env(p_data *data);
int builtin_unset_env(p_data *data);

/*env_.c */
char *env_get_key(char *name, p_data *data);
int env_set_key(char *key, char *value, p_data *data);
int env_remove_key(char *key, p_data *data);
void print_environ(p_data *data);


/*helpers_m.c */
void long_to_string(long number, char *string, int base);
int _atoi(char *s);
int count_characters(char *string, char *character);

/* helpers_s.c */
int str_length(char *string);
char *str_duplicate(char *string);
int str_compare(char *str1, char *str2, int number);
char *str_concat(char *str1, char *str2);
void str_reverse(char *string);

/*helpers_p.c */
int _print(char *string);
int _print1(char *string);
int _print_error(int errorcode, p_data *data);


#endif /* SHELL_H */

