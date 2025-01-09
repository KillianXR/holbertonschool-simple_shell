#include "main.h"
/**
 * _splitline - Split a line of input into tokens/arguments.
 * @line: The input string to be split.
 *
 * Return: A pointer to the array of arguments.
 */
char **_splitline(char *line)
{
	char **args, **newargs, *token;
	int count, position = 0;
	int size = 64;

	args = malloc(size * sizeof(char *));

	if (!args)
	{
	perror("malloc failed");
	free(line);
	exit(1);
	}
	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
	args[position] = token;
	position++;

	if (position >= size)
	{
	size = size * 2;
	newargs = malloc(size * sizeof(char *));
	if (!newargs)
	{
	perror("malloc failed");
	free(line);
	free(args);
	exit(1);
	}
	for (count = 0; count < position; count++)
		{
		newargs[count] = args[count];
		}
		free(args);
		args = newargs;
	}
	token = strtok(NULL, " \t\r\n\a");
	}
	args[position] = NULL;
	return (args);
}
