#ifndef SHELL_H_

#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "macro.h"

typedef struct info /*program data structure*/
{
	char *input_line; /*input read for fetch*/
	char *program_name;/*executable file name*/
	char *command_name;/*command typed by first user*/
	char **env;/*environment copy*/
	char **tokens;/*tokenized array array of input pointer*/
	char **alias_list;/*pointer arrays with aliases*/
	int file_descr;/*input command describtion*/
	int ex_count;/*# executed commands*/
} program_data;

typedef struct built_in /*structure for built_in functions*/
{
	int (*function)(program_data *data);/*function called for built_in functions*/
	char *built_in;/*name*/

} built_in;

int fetch(program_data *data);/*reading data*/
int check(char *a_com[], int x, char a_op[]);/*if logical operators exist, split lines*/

void inf_loop(char *prompt, program_data *data);/*prompt shown because of infinite loop*/
void init_data(program_data *data, int arc, char *argv[], char **env);/*structuring with the info of the program*/
void cnrl(int opr UNUSED);/*prompt printed in new line*/

int change(program_data *data);/*executing a command*/

int list(program_data *data);/*execute if builtin matches*/

void p_alias(program_data *data);
void p_variables(program_data *data);
int buffer_p(char *buffer, char *str_add);

char *_strtok(char *line, char *del);/*pointer in part of array creation*/
void tokenize(program_data *data);

char **tokenize_path(program_data *data);
int find_program(program_data *data);

void recurrent_data(program_data *data);
void free_pointers(char **directories);
void free_data(program_data *data);

int builtin_env(program_data *data);/*shell running environment*/
int builtin_unset_env(program_data *data);/*delete variable*/
int builtin_set_env(program_data *data);/*override or create variable*/

int more_alias(program_data *data);/*set, show and unset alias*/
int work_directory(program_data *data, char *dirx);/*setting work directory*/
int exit_out(program_data *data);/*closing shell*/
int cd_in(program_data *data);/*changing directory going into*/
int help(program_data *data);/*show help*/

int print1(char *string);/*prints standard output string*/
int print2(char *string);/*prints standard error string*/
int printErr(int errorcode, program_data *data);/*standard errror string print*/

int setkey(char *key, char *value, program_data *data);/*overwriting environment variable value*/
char getkey(char *name, program_data *data);/*getting environment variable value*/
int deletekey(char *key, program_data *data);/*key removal from environment*/
void printEnv(program_data *data);/*print staus on environment*/

int string_l(char *string);/*character count*/
int string_c(char *string1, char *string2, int num);/*comparison*/
char string_d(char *string);/*duplication*/
void string_r(char *string);/*reversal*/
char string_cc(char *string1, char *string2);/*concatenation*/

void int_to_string(long num, char *string, int base);/*change from interger to string*/
int string_to_num(char *s);/*change from string to number*/
int count(char *string, char *character);/*print number of certain characters in string*/

char get_a(program_data *data, char *alias);/*get alias name*/
int set_a(char *alias_str, program_data *data);/*give alias name*/
int print_a(program_data *data, char *alias);/*print alias list*/

#endif
/*Code by Frank Ndlovu & Nomcebo Mncina*/
