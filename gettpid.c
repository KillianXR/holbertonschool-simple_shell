#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * gettpid - give the PID of the terminal
 *
 * Return: Always 0.
 */
int gettpid(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("%u\n", my_pid);
	return (0);
}
