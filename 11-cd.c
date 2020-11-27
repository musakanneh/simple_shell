#include "holberton.h"

/**
 * implement_cd - execute cd builtin
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int implement_cd(config *build)
{
	register uint count = 0;
	_Bool can_change = false;

	count = count_args(build->args);
	if (count == 1)
	{
		can_change = cd_to_home(build);
	}
	else if (count == 2 && _strcmp(build->args[1], "-") == 0)
	{
		can_change = cd_to_previous(build);
	}
	else
	{
		can_change = cd_to_custom(build);
	}
	if (can_change)
	{
		update_environ(build);
	}
	return (1);
}

/**
 * cd_to_home - change directory to home
 * @build: input build
 * Return: true on success, false on failure
 */
_Bool cd_to_home(config *build)
{
	register int i;
	char *str, *ptr;

	i = search_node(build->env, "HOME");
	if (i == -1)
	{
		return (true);
	}
	str = get_node_at_index(build->env, i);
	ptr = _strchr(str, '=');
	ptr++;
	chdir(ptr);
	return (true);
}

/**
 * cd_to_previous - change directory to previous directory -
 * address is found in OLDPWD env var
 * @build: input build
 * Return: true on success, false on failure
 */
_Bool cd_to_previous(config *build)
{
	register int i;
	char *str, *ptr;
	char *current = NULL;

	current = getcwd(current, 0);
	i = search_node(build->env, "OLDPWD");
	if (i == -1)
	{
		chdir(current);
		write(STDOUT_FILENO, current, _strlen(current));
		put_new_line();
		return (true);
	}
	str = get_node_at_index(build->env, i);
	ptr = _strchr(str, '=');
	ptr++;
	chdir(ptr);
	write(STDOUT_FILENO, ptr, _strlen(ptr));
	put_new_line();
	return (true);
}

/**
 * cd_to_custom - change directory to what user inputs in
 * @build: input build
 * Return: true on success, false on failure
 */
_Bool cd_to_custom(config *build)
{
	register int changeStatus;

	changeStatus = chdir(build->args[1]);
	if (changeStatus == -1)
	{
		errno = EBADCD;
		handle_errors(build);
		return (false);
	}
	return (true);
}

/**
 * updateEnviron - change environmental variables
 * @build: input build
 * Return: true on success false on failure
 */
_Bool update_environ(config *build)
{
	register int i;

	i = update_old(build);
	update_cur_dir(build, i);
	return (true);
}
