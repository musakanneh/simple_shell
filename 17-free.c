#include "holberton.h"

/**
 * free_member - free build config members
 * @build: input build params
 * Return: Nothing
 */
void free_member(config *build)
{
	if (build->env)
	{
		free_list(build->env);
		free(build->env);
	}
	if (build->args)
	{
		free_args(build->args);
		free(build->args);
	}
	if (build->buffer)
	{
		free(build->buffer);
	}
}

/**
 * free_list - frees a linked list
 * @head: double pointer to head of list
 */
void free_list(linked_l *head)
{
	linked_l *current;
	linked_l *tmp;

	if (!head)
	{
		return;
	}
	current = head;
	while (current)
	{
		tmp = current;
		current = tmp->next;
		free(tmp->string);
	}
	head = NULL;
}

/**
 * free_args - a function that frees double pointer arg
 * @args: array of char pointers
 */
void free_args(char **args)
{
	register uint i = 0;

	while (args[i])
	{
		free(args[i++]);
	}
	/*free(args);*/
}

/**
 * free_args_and_buffer - frees args and buffer
 * @build: input build
 */
void free_args_and_buffer(config *build)
{
	free_args(build->args);
	free(build->buffer);
}
