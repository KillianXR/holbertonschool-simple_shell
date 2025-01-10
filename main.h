#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Function Prototypes */
int main(void);
char **_splitline(char *line);
int _execute(char **args);

/* Déclaration de l'environnement */
extern char **environ;

#endif /* MAIN_H */
