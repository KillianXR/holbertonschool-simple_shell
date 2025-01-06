#include "main.h"

/**
 * _execute - Executes a command using execve.
 * @args: The array of arguments for the command to execute.
 *
 * Return: 0 on success, 1 on failure.
 */
int _execute(char **args)
{
	pid_t child_pid;
	int status;
	/* Déclaration de l'environnement */
	extern char **environ;

	if (args[0] == NULL)
		return (1);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
	if (execve(args[0], args, environ) == -1)
	{
	perror("/.simple_shell");
	/* Libération de args en cas d'échec */   
	free(args);
	exit(1);
	}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
