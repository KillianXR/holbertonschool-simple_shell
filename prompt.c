#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
/**
*
*
*
*/
int main (void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nbread;

	while (1)
	{
		printf("$ ");

		nbread = getline(&line, &len, stdin);
		if (nbread == -1)
			{
			break;
			}
		printf("%s", line);
	}
    free(line);
    return (0);
}