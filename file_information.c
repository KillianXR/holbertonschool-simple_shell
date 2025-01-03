#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * main - find the full path of a file
 * @count_argument: count argument
	* @vector_argument: vector argument
 * Return: Always 0.
 */
int main(int count_argument, char **vector_argument)
{
	unsigned int count;
	struct stat stock;

	if (count_argument < 2)
	{
	printf("Usage: %s path_to_file ...\n", vector_argument[0]);
	return (1);
	}
	count = 1;

	while (vector_argument[count])
	{
	printf("%s:", vector_argument[count]);
	if (stat(vector_argument[count], &stock) == 0)
		{
		printf(" FOUND\n");
		}
	else
		{
		printf(" NOT FOUND\n");
		}
	count++;
	}
	return (0);
}
