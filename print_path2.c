#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/*Declares environ as external*/
extern char **environ;

/* Linked list node structure */
typedef struct Node
{
	char *directory;
	struct Node *next;
} Node;

/* Function prototypes */
char *_getenv(const char *name);
Node *build_path_list(void);
void print_path_list(Node *head);
void free_path_list(Node *head);

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable to search for.
 *
 * Return: The value of the environment variable if found, otherwise NULL.
 */
char *_getenv(const char *name)
{
	char **env;
	size_t len;

	if (name == NULL || *name == '\0')
	return (NULL);

	len = strlen(name);

	for (env = environ; *env != NULL; env++)
	{
	if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
	{
	return (*env + len + 1);
	}
	}

	return (NULL);
}

/**
 * build_path_list - Builds a linked list of directories from
 * the PATH environment variable.
 *
 * Return: Pointer to the head of the linked list.
 */
Node *build_path_list(void)
{
	char *path;
	char *token;
	char *path_copy;
	Node *head = NULL;
	Node *tail = NULL;

	path = _getenv("PATH");
	if (path == NULL)
	{
	fprintf(stderr, "PATH environment variable not found\n");
	return (NULL);
	}

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
	perror("strdup");
	return (NULL);
	}

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
	Node *new_node = malloc(sizeof(Node));

	if (new_node == NULL)

	{
		perror("malloc");
		free(path_copy);
		free_path_list(head);
		return (NULL);
	}
	new_node->directory = strdup(token);
	if (new_node->directory == NULL)
	{
		perror("strdup");
		free(new_node);
		free(path_copy);
		free_path_list(head);
		return (NULL);
	}
	new_node->next = NULL;

	if (head == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		tail->next = new_node;
		tail = new_node;
	}

	token = strtok(NULL, ":");
	}

	free(path_copy);
	return (head);
}

/**
 * print_path_list - Prints each directory in the linked list.
 * @head: Pointer to the head of the linked list.
 */
void print_path_list(Node *head)
{
	Node *current = head;

	while (current != NULL)
	{
	printf("%s\n", current->directory);
	current = current->next;
	}
}

/**
 * free_path_list - Frees the linked list and its nodes.
 * @head: Pointer to the head of the linked list.
 */
void free_path_list(Node *head)
{
	Node *current = head;
	Node *next;

	while (current != NULL)
	{
	next = current->next;
	free(current->directory);
	free(current);
	current = next;
	}
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	Node *path_list = build_path_list();

	if (path_list == NULL)
	return (1);

	print_path_list(path_list);
	free_path_list(path_list);

	return (0);
}
