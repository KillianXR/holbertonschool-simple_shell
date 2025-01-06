#include "main.h"
/**
 * _splitline - Split a line of input into tokens/arguments.
 * @line: The input string to be split.
 *
 * Return: A pointer to the array of arguments.
 */
char **_splitline(char *line)
{
 char *token;
 char **args = malloc(64 * sizeof(char *));
 int position = 0;

 if (!args)
 {
 perror("malloc failed");
	free(line);
	free(args);
	exit(1);
 }
	/* Split by space, tab, or new line */
 token = strtok(line, " \t\r\n\a"); 
 while (token != NULL)
 {
	args[position] = token; 
	position++;

	/* Reallocate if more space is needed */
	if (position >= 64)
 {
  args = realloc(args, 128 * sizeof(char *));
  if (!args)
  {
		perror("realloc failed");
		free(line);
		free(args);
		exit(1);
  }
 }

 token = strtok(NULL, " \t\r\n\a"); 
 }
 args[position] = NULL;
 return (args);
}
