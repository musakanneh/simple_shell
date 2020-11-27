#include "holberton.h"

/**
 * add_node_to_front - adds a new node at the beginning of a linked_l list
 * @head: reference to head of linked list
 * @str: string to be added on new node
 * Return: address of new head;
 */
linked_l *add_node_to_front(linked_l **head, char *str)
{
	linked_l *newNode;
	char *new_str;

	if (!str)
		return (NULL);
	newNode = malloc(sizeof(linked_l));
	if (!newNode)
	{
		perror("Malloc failed\n");
		exit(errno);
		free(newNode);
	}
	new_str = _strdup(str);
	if (!new_str)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newNode->string = new_str;
	newNode->next = *head;
	*head = newNode;
	/*free(newNode);*/
	return (*head);
}

/**
 * addNodeEnd - adds a new node at the end of a linked_l list;
 * @head: reference to head of list
 * @str: string to be added to linked list
 * Return: address of new node
 */
linked_l *add_node_to_end(linked_l **head, char *str)
{
	linked_l *newNode;
	linked_l *last = *head;
	char *newStr;

	if (!str)
		return (NULL);
	newNode = malloc(sizeof(linked_l));
	if (!newNode)
	{
		perror("Malloc failed\n");
		exit(errno);
		free(newNode);
	}
	newStr = _strdup(str);
	if (!newStr)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newNode->string = newStr;
	newNode->next = NULL;
	if (!*head)
	{
		*head = newNode;
		return (newNode);
	}
	while (last->next)
		last = last->next;
	last->next = newNode;
	return (last);
}

/**
 * print_list - prints all elements of a linked_l list
 * @h: pointer to head of list
 * Return: number of elements
 */
size_t print_list(const linked_l *h)
{
	register int count = 0;

	while (h)
	{
		write(STDOUT_FILENO, h->string, _strlen(h->string));
		put_new_line();
		h = h->next;
		count++;
	}

	return (count);
}

/**
 * delete_node_at_index - deletes the node at index
 * index of a linked_l linked list
 * @head: double pointer to head of list
 * @index: index of node to be deleted
 * Return: 1 if success, -1 if fail
 */
int delete_node_at_index(linked_l **head, unsigned int index)
{
	linked_l *current;
	linked_l *next;

	register uint i;

	if (!head || !(*head))
		return (-1);
	current = *head;
	if (!index)
	{
		*head = current->next;
		return (1);
	}
	for (i = 0; current && i < index - 1; i++)
		current = current->next;
	if (!current || !(current->next))
		return (-1);
	next = current->next->next;
	free(current->next->string);
	current->next = next;
	/* free(current->next); */
	return (1);
}

/**
 * list_len - returns the number of elements in a linked list
 * @h: head of linked list
 * Return: number of elements in list_t
 */
size_t list_len(linked_l *h)
{
	register unsigned int count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}
	return (count);
}
