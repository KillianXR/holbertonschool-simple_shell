#include <unistd.h>
#include <stdio.h>
#include "main.h"
/**
	* print_argument - print strings of a double pointer
	* @ac: number of arguments
	* @av: given arguments
	* Return: 0
 */
int print_argument(int ac, char **av)
{
	char **args;

	for (args = av; *args != NULL; args++)
	{
		printf("%s\n", *args);
	}

	return (0);
}
