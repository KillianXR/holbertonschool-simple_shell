#include <stdio.h>
/**
 * main - print all variable of environment
 * @env: array containing variable of environment
	* @count_argument: no used
	* @vector_argument: no used
 * Return: Always 0.
 */
int main(int count_argument, char **vector_argument, char **env)
{
	unsigned int count = 0;
	(void)count_argument;
	(void)vector_argument;

	while (env[count] != NULL)
	{
	printf("%s\n", env[count]);
	count++;
	}
	return (0);
}
