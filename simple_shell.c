#include "main.h"
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

	while (1)
	{
	/* Displays a prompt for the user */
	printf("❓ UnknownCommand> ");
	nread = getline(&line, &len, stdin);
	/* Exit the loop on error or EOF */
	if (nread == -1)
	{
	free(line);
	break;
	}
	/* Remove the new line character from input */
	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	/* Exit the program if the command is exit */
	if (strcmp(line, "exit") == 0)
	{
	free(line);
	break;
	}
	/* Split the line into arguments then execute the command */
	args = _splitline(line);
	_execute(args);
	free(line);
	free(args);
	}
	/* Ensure memory is freed before exiting */
	if (line)
	{
	free(line);
	line = NULL;
	}
	free(line);
	return (0);
}
