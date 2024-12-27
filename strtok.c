#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
	* main - sépare une phrase en utilisant strtok
 */
int main(void)
{
	char *strtoken;
	char string [] = ("ceci est une phrase, que l'on va séparer.");
	const char *separator = (" ,?!_.'");

	strtoken = strtok(string, separator);
	while (strtoken)
	{
	printf("%s\n", strtoken);
	strtoken = strtok ( NULL, separator);
	}
	return (0);
}