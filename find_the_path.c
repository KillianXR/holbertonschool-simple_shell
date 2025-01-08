#include "main.h"

/**
 * find_path - Looks for a command in each directory specified in the PATH 
	* environment variable
 * @cmd: pointer to the command
 * Return: pointer to string containing the full path
*/
char *find_path(char *cmd)
{
	struct stat st;
	int stat_ret, i;
	char buf[PATH_MAX_LENGTH], *path, *ret, **dir;

	path = get_path();
	if (!path)
		return (NULL);
	dir = tokenize(path, PATH_SEPARATOR);
	if (!dir)
		return (NULL);
	for (i = 0; dir[i]; i++)
	{
		_memset(buf, 0, PATH_MAX_LENGTH);
		_strcpy(buf, dir[i]);
		_strcat(buf, "/");
		_strcat(buf, command);
		stat_ret = stat(buf, &st);
		if (stat_ret == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			free_tokens(dir);
			ret = malloc(sizeof(char) * (strlen(buf) + 1));
			if (!ret)
				return (NULL);
			strcpy(ret, buf);
			return (ret);
		}
	}
	if (stat_ret == -1)
		free_tokens(dir);
	return (NULL);
}

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
}
