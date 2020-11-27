#include "holberton.h"

/**
 * checkPath - searches $PATH for directory of command
 *
 * Description: checks the path of a given command
 * @build: input build
 * Return: the state of the path values
 */
_Bool check_path(config *build)
{
	register int len;
	static char buffer[BUFSIZE];
	struct stat st;
	char *token, *copy, *delim = ":", *tmp;
	_Bool inLoop = false;

	if (validate_constraints(build))
		return (true);
	copy = _strdup(build->path);
	token = _strtok(copy, delim);
	while (token)
	{
		tmp = inLoop ? token - 2 : token;
		if (*tmp == 0 && stat(build->args[0], &st) == 0)
		{
			build->full_path = build->args[0];
			return (true);
		}
		len = _strlen(token) + _strlen(build->args[0]) + 2;
		_strcat(buffer, token);
		_strcat(buffer, "/");
		_strcat(buffer, build->args[0]);
		get_null_bytes(buffer, len - 1);
		if (stat(buffer, &st) == 0)
		{
			build->full_path = buffer;
			free(copy);
			return (true);
		}
		get_null_bytes(buffer, 0);
		token = _strtok(NULL, delim);
		inLoop = true;
	}
	build->full_path = build->args[0];
	return (false);
}

/**
 * checkEdgeCases - helper func for check path to check edge cases
 * @build: input build
 * Return: true if found, false if not
 */
_Bool validate_constraints(config *build)
{
	char *copy;
	struct stat st;

	copy = _strdup(build->path);
	if (!copy)
	{
		build->full_path = build->args[0];
		return (true);
	}
	if (*copy == ':' && stat(build->args[0], &st) == 0)
	{
		build->full_path = build->args[0];
		return (true);
	}
	free(copy);
	return (false);
}
