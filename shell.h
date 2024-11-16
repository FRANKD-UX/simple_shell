#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* Global environment variable */
extern char **environ;

/* Main shell functionality */
void run_non_interactive_mode(void);
void run_non_interactive_mode(const char *script_path);

/* Tokenizer */
char **tokenize_input(const char *input);

/* Command processor */
void process_command(char *line);

/* Built-in commands */
void handle_exit(char **args);
void handle_cd(char **args);
void handle_env(void);

/* Utility functions */
void free_tokens(char **tokens);
void print_error(const char *msg);

#endif /* SHELL_H */
