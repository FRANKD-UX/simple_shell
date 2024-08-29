int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		}

		nread = getline(&buffer, &bufsize, stdin);

		if (nread == -1)
		{
			free(buffer);
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		if (nread > 0 && buffer[nread - 1] == '\n')
			buffer[nread - 1] = '\0';

		if (strcmp(buffer, "") == 0)
			continue;

		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(0);
		}

		execute_command(buffer);
	}

	free(buffer);
	return (0);
}

