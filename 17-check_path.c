#include "holberton.h"

/**
 * checkPath - searches $PATH for directory of command
 *
 * Description: checks the path of a given command
 * @build: input build
 * Return: the state of the path values
 */
_Bool checkPath(config *build)
{
	register int len;
	static char buffer[BUFSIZE];
	struct stat st;
	char *tok, *copy, *delim = ":", *tmp;
	_Bool inLoop = false;

	if (checkEdgeCases(build))
		return (true);
	copy = _strdup(build->path);
	tok = _strtok(copy, delim);
	while (tok)
	{
		tmp = inLoop ? tok - 2 : tok;
		if (*tmp == 0 && stat(build->args[0], &st) == 0)
		{
			build->full_path = build->args[0];
			free(copy);
			return (true);
		}
		len = _strlen(tok) + _strlen(build->args[0]) + 2;
		_strcat(buffer, tok);
		_strcat(buffer, "/");
		_strcat(buffer, build->args[0]);
		get_null_bytes(buffer, len - 1);
		if (stat(buffer, &st) == 0)
		{
			free(copy);
			build->full_path = buffer;
			return (true);
		}
		get_null_bytes(buffer, 0);
		tok = _strtok(NULL, delim);
		inLoop = true;
	}
	build->full_path = build->args[0];
	free(copy);
	return (false);
}

/**
 * checkEdgeCases - helper func for check path to check edge cases
 * @build: input build
 * Return: true if found, false if not
 */
_Bool checkEdgeCases(config *build)
{
	char *copy;
	struct stat st;

	copy = _strdup(build->path);
	if (!copy)
	{
		build->full_path = build->args[0];
		free(copy);
		return (true);
	}
	if (*copy == ':' && stat(build->args[0], &st) == 0)
	{
		build->full_path = build->args[0];
		free(copy);
		return (true);
	}
	free(copy);
	return (false);
}
