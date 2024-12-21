#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
* main - program that executes the command
* ls -l /tmp in 5 different child processes.
* Return: 0 if its succeed or 1 if its failed.s
*/
int main(void)
{
	pid_t child_pid;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	/* count the number of child process created */
	int count = 0;

	while (count < 5)
	{
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
			return (1);
		}
	}
		else
		{
			wait(&status);
			count++;
		}
	}
	return (0);
}
