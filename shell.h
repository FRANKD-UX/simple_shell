#ifndef SHELL_H
#define SHELL_H

void run_interactive_mode(void);
void run_non_interactive_mode(const char *script_path);
void execute_command(char *command);

#endif /* SHELL_H */

