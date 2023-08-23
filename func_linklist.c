#include "shell.h"

/**
 * lk_path - build a linked list for path directories.
 *
 * @path: string of path value.
 *
 * Return: a pointer to the created linked list.
 */
lpath *lk_path(char *path)
{
	lpath *head = '\0';
	char *token;
	char *cpy_path = _strdup(path);

	token = strtok(cpy_path, ":");
	while (token)
	{
		head = add_node_end(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/**
 * add_node_end - adds a new node at the end of a list_t list.
 *
 * @head: a pointer to the head of the linked list.
 * @str: a pointer to string in previous first node.
 *
 * Return: address of the new node.
 */
lpath *add_node_end(lpath **head, char *str)
{

	lpath *tmp;
	lpath *new;

	new = malloc(sizeof(lpath));

	if (!new || !str)
	{
		return (NULL);
	}

	new->dir = str;
	new->np = '\0';

	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;

		while (tmp->np)
		{

			tmp = tmp->np;
		}

		tmp->np = new;
	}

	return (*head);
}

/**
 * free_list - frees a linked list
 *
 *@head: pointer to our linked list
 */
void free_list(lpath *head)
{
	lpath *size;

	while (head)
	{
		size = head->np;
		free(head->dir);
		free(head);
		head = size;
	}

}
