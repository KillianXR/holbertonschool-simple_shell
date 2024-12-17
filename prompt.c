#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
/**
* prompt - prompt and a program that prints "$ ",
* wait for the user to enter a command, prints it on the next line
* Return: 0 or nothing
*/
int prompt(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nbread;

	while (1)
	{
	/* Prints the prompt */
		printf("$ ");
	/* Reads a line from the Standard Input */
		nbread = getline(&line, &len, stdin);
	/* Breaks the loop if EOF is reached */
	if (nbread == -1)
	{
		break;
	}
	/* Prints the input line */
	printf("%s", line);
	}
	free(line);
	return (0);
}
