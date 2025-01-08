#include "main.h"

/**
 * main - simple UNIX command interpreter
 *
 * This program displays a prompt, waits for input from the user,
 * executes the command, and exits on the "exit" command or EOF (Ctrl+D).
 *
 * Return: 0 (Success).
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;
	pid_t child_pid;
	int status;

	while (1)
	{
		/* Display the prompt */
		printf("cisfun#");
		nread = getline(&line, &len, stdin);

		/* Handle EOF (Ctrl+D) and errors */
		if (nread == -1)
		{
			free(line);
			printf("\n");
			break;
		}

		/* Remove the new line character from input */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* Exit if the user types "exit" */
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			break;
		}

		/* Split the line into arguments */
		args = malloc(sizeof(char *) * 2);  // Only one argument
		if (!args)
		{
			perror("malloc");
			free(line);
			continue;
		}

		args[0] = line;  // Only the command itself
		args[1] = NULL;   // NULL-terminate the arguments array

		/* Fork and execute the command */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			free(args);
			free(line);
			continue;
		}

		if (child_pid == 0)  // Child process
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("./simple_shell");
			}
			exit(1);  // Exit child process if execve fails
		}
		else  // Parent process
		{
			wait(&status);  // Wait for the child process to finish
		}

		/* Free allocated memory */
		free(args);
	}

 /* free and return */
	free(line);
	return (0);
}