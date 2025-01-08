#include"main.h"

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
 * execute_cmd - function to execute the command
 * @cmd: the command to execute.
 */
void execute_cmd(char **cmd)
{
	pid_t	pid = 0;
	int		status = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}

	else
	{
		if (execve(cmd[0], cmd, NULL) == -1)
			perror("shell");
		exit(EXIT_FAILURE);
	}
}
