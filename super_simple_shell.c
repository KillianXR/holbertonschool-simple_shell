#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
/**
* main -  first version of a super simple shell
* that can run commands with their full path, without any argument.
* Return: 0 if its succeed, or 1 if its failed
*/
int main(void)
{
	pid_t pid;
	size_t length = 0;
	ssize_t nchar;
	char *line = NULL;
	int status;

	while (1)
	{
	/* Prints the prompt */
		printf("$ ");
	/* Reads a line from the Standard Input */
		nchar = getline(&line, &length, stdin);
	/* Breaks the loop if EOF is reached */
	if (nchar == -1)
	{
		free(line);
		exit(0);
	}
	/* Prints the input line */
	printf("%s", line);
	}
	free(line);
	exit(0);

	if (line[nchar - 1] == '\n')
	{
	line[nchar - 1] = '\0';
	}

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		free(line);
		exit(1);
	}

	if (pid == 0)
	{
		char *argv[2];
		argv[0] = line;
		argv[1] = NULL;
		if (line[0] == '/')
		{
			if (execve(line, argv, NULL) == -1)
			{
				perror("./hsh");
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(line);
	return (0);
}
