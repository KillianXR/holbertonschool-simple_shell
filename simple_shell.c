#include "main.h"
/**
* main - simple UNIX command interpreter
*
* Return: nothing.
*/

int main(void)
{
 char *line = NULL;
 size_t len = 0;
 ssize_t nread;
 char **args;

 while (1)
 {
 printf("❓ UnknownCommand> ");
 nread = getline(&line, &len, stdin);
 if (nread == -1)
 {
  free(line);
		break;  /* Sortie de la boucle en cas d'erreur ou EOF */
 }

 if (line[nread - 1] == '\n')
  	line[nread - 1] = '\0';

 if (strcmp(line, "exit") == 0)
 {
  	free(line);
			break;  /* Sortie de la boucle si la commande est "exit" */
 }

 args = _splitline(line);
 _execute(args);
	free(line);
 free(args);
 }

 /* Assurez-vous que line est libéré avant de quitter */
 if (line)
 {
  free(line);
  line = NULL;
 }
 free(line);
 return (0);
}
