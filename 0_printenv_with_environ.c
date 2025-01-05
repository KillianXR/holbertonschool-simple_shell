#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	char *env;
	extern char **environ;
	int count;
   
	for (count = 0; environ[count] != NULL; count++) 
	{
		env = environ[count];
		printf("%s\n", env);
	}

	return (0);
}