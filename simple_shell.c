#include "main.h"

#define PROMPT "$ " /* Définition de l'invite de commande */
/**
* main - simple UNIX command interpreter
* This programms displays a prompt and wait an input
* comming from an user, then it executes the command
* and to exit, use exit or EOF.
* Return: 0 (Success).
*/

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;
	int interactive;

	interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
		{
			write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
		}
	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
	free(line);
	break;
	}
	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	if (strcmp(line, "exit") == 0)
	{
	free(line);
	break;
	}
	args = _splitline(line);
	_execute(args);
	free(line);
	free(args);
	}
	if (line)
	{
	free(line);
	line = NULL;
	}
	free(line);
	return (0);
}
