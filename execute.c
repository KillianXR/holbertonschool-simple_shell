#include"main.h"
/**
 * exec_cmd - function execute the commande
 * @cmd: the commande to execute
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

void main()
{
	
}