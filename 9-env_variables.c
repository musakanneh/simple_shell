#include "holberton.h"

/**
 * env_function - prints the environment
 * @build: input build
 * Return: Always 1
 */
int env_function(config *build)
{
	print_list(build->env);
	return (1);
}

/**
 * set_env_func - adds env variable if it does not exist;
 * modify env variable if it does
 * @build: input build
 * Return: Always 1
 */
int set_env_func(config *build)
{
	register int index, len;
	static char buffer[BUFSIZE];

	if (count_args(build->args) != 3)
	{
		errno = EWSIZE;
		handle_errors(build);
		return (1);
	}
	len = _strlen(build->args[1]) + _strlen(build->args[2]) + 2;
	_strcat(buffer, build->args[1]);
	_strcat(buffer, "=");
	_strcat(buffer, build->args[2]);
	get_null_bytes(buffer, len - 1);
	index = search_node(build->env, build->args[1]);
	if (index == -1)
	{
		add_node_to_end(&build->env, buffer);
		get_null_bytes(buffer, 0);
		return (1);
	}
	delete_node_at_index(&build->env, index);
	add_node_at_index(&build->env, index, buffer);
	get_null_bytes(buffer, 0);
	return (1);
}

/**
 * unset_env_func - deletes env variable if exists;
 * will only accept valid variables names
 * @build: input build
 * Return: Always 1
 */
int unset_env_func(config *build)
{
	register int foundVar, i = 1;
	_Bool foundMatch = false;

	while (build->args[i])
	{
		if (is_alpha(build->args[i][0]) || build->args[i][0] == '_')
		{
			foundVar = search_node(build->env, build->args[i]);
			if (foundVar > -1)
			{
				delete_node_at_index(&build->env, foundVar);
				foundMatch = true;
			}
		}
		i++;
	}
	if (foundMatch == false)
	{
		errno = ENOSTRING;
		handle_errors(build);
	}
	return (1);
}

/**
 * is_alpha - checks if c is an alphabetic character
 * @c: potential alphabetical value
 * Return: if c is a letter, returns 1. Otherwise, return 0.
 */
int is_alpha(int c)
{
	if (c > 64 && c < 91)
	{
		return (1);
	}
	else if (c > 96 && c < 123)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
