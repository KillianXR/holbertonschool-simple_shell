#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
	* main - put the path directories in a linked list
	* Return: void
 */
void main() 
{
	char *path = getenv("PATH");
	if (!path) {
		printf("PATH environment variable is not set\n");
		return;
	}

	list_t *head = NULL;
	list_t *current = NULL;
	char *dir = strtok(path, ":");

	while (dir != NULL)
	{
		list_t *new_node = (list_t *)malloc(sizeof(list_t));
		if (!new_node) {
			printf("Memory allocation failed\n");
			return;
		}
		new_node->str = strdup(dir);
		new_node->next = NULL;

		if (head == NULL) 
		{
			head = new_node;
		}
		else 
		{
			current->next = new_node;
		}

		current = new_node;
		dir = strtok(NULL, ":");
	}

	printf("Directories in PATH:\n");
	current = head;
	while (current != NULL)
	{
		printf("%s\n", current->str);
		current = current->next;
	}

	current = head;
	while (current != NULL)
	{
		list_t *next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
}
