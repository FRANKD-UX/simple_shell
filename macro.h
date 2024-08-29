#ifndef H_HELPER
#define H_HELPER
#define BUFFER_SIZE 1024 /* buffer size for each call in  fetch */
#define MSG_PROMPT "shell_101" /* A prompt to be printed */
#define UNUSED __attribute__((unused))

#define HELP_CD_IN_MSG "cd=\n"\
"cd:\tcd [dir]\n\n"\
"	Change the shell working directory.\n\n"\
"	If no argument is given to cd the command will be interpreted\n"\
"	as cd $HOME.\n"\
"	if argument help is - (cd -), the command will be interpreted\n"\
"	as cd $OLDPWD.\n\n"

#define HELP_EXIT_OUT_MSG "exit=\n"\
"exit:\texit [STAT]\n\n"\
"	Exit of the simple-shell.\n\n"\
"	Exits the shell with a stat of N and if N is omitted, the exit stat\n"\
"	is the last command executed.\n\n"

#define HELP_ENV_MSG "env=\n"\
"env:\tenv \n\n"\
"	Print environment.\n\n"\
"	The command env will be print a complete list of environment variables.\n\n"

#define HELP_UNSET_ENV_MSG "unsetenv=\n"\
"unsetenv:\tunsetenv VAR\n\n"\
"	The function unsetenv deletes one variable from the environment.\n\n"\
"	Case where there are no correct numbers of arguments, print error message.\n\n"

#define HELP_SET_ENV_MSG "setenv=\n"\
"setenv:\tsetenv VAR_VALUE\n\n"\
"	Change or add an environment variable.\n\n"\
"	Alternatively initialize new environment variabl,  modify an existing one\n"\
"	In case of no correct numbers of arguments, print error message.\n\n"

#define MSG_HELP "help=\n"\
"help:\thelp [B_NAME]\n\n"\
"	Display info about the builtin commands.\n\n"\
"	Displays of builtin commands summaries.  \n"\
"	If B_NAME is specified, gives details on all commands matching B_NAME,\n"\
"	else, list of help topics are printed as B_NAME list.\n"\
"	Arguments:\n\n"\
"	B_NAME specifies help topics.\n\n"\
"	cd\t[dir]\n"\
"	exit\t[stat]\n"\
"	env\n"\
"	setenv\t[var value]\n"\
"	unset\t[var]\n"\
"	help\t[b_name]\n\n"

#endif

