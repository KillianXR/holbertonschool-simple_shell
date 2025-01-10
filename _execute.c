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
	char *command;

	if (args[0] != NULL && strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}

	if (args[0] == NULL)
		return (1);

	command = _find_path_command(args[0]);
	if (!command)
	{
		perror(args[0]);
		return (1);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		free(command);
		return (1);
	}
	else if (child_pid == 0)
	{
	if (execve(command, args, environ) == -1)
	{
	perror("/.simple_shell");
	free(args);
	free(command);
	exit(1);
	}
	}
	else
	{
		wait(&status);
	}
	free(command);
	return (0);
}

/**
 * _find_path_command - Finds the full path of a command.
 * @command: The command to find.
 *
 * Return: Full path of the command if found, NULL otherwise.
 */
char *_find_path_command(char *command)
{
	char *path, *directory, *full_path;
	struct stat command_stat;
	int length;

	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &command_stat) == 0 && (command_stat.st_mode & S_IXUSR))
			return (strdup(command));
		return (NULL);
	}
	path = getenv("PATH");
	if (!path)
		path = "/bin:/usr/bin";

	path = strdup(path);
	if (!path)
		return (NULL);
	directory = strtok(path, ":");
	while (directory != NULL)
	{
		length = strlen(directory) + strlen(command) + 2;
		full_path = malloc(length);
		if (!full_path)
		{
			free(path);
			return (NULL);
		}
		snprintf(full_path, length, "%s/%s", directory, command);

		if (stat(full_path, &command_stat) == 0 && (command_stat.st_mode & S_IXUSR))
		{
			free(path);
			return (full_path);
		}

		free(full_path);
		directory = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
