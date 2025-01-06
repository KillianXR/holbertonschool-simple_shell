#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - prints each directory contained in the the environment variable PATH.
 *
 * Return: 0 if it is succesful, 1 otherwise.
 */
int main(void)
{
	char *path;
	char *token;
	char *path_copy;

	path = getenv("PATH");
	if (path == NULL)
	{
	fprintf(stderr, "Error: PATH environment variable is not defined.\n");
	return (1);
	}

	/* Creates a copy of the PATH variable */
	path_copy = strdup(path);
	if (path_copy == NULL)
	{
	perror("Memory allocation error");
	return (1);
	}

	/* Split PATH into directories */
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
	printf("%s\n", token); /* Print each directory */
	token = strtok(NULL, ":");
	}

	/* Free allocated memory */
	free(path_copy);
	return (0);
}
