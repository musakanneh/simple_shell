#include "holberton.h"

/**
 * update_old - updates OLDPWD to current PWD
 * @build: input build
 * Return: index in linked list of PWD on success -
 * If PWD or OLDPWD does not exist in environ vars,
 * return -1
 */
int update_old(config *build)
{
	register int pwdIndex = 0, index = 0;
	static char old[BUFSIZE];
	char *current = NULL;

	_strcat(old, "OLD");
	pwdIndex = search_node(build->env, "PWD");
	if (pwdIndex == -1)
	{
		return (-1);
	}
	current = get_node_at_index(build->env, pwdIndex);
	_strcat(old, current);
	get_null_bytes(old, _strlen(current) + 4);
	/* free(current); */
	index = search_node(build->env, "OLDPWD");
	if (index == -1)
	{
		return (-1);
	}
	delete_node_at_index(&build->env, index);
	add_node_at_index(&build->env, index, old);
	get_null_bytes(old, 0);
	return (pwdIndex);
}

/**
 * update_cur_dir - updates PWD to accurately reflect current directory
 * @build: input build
 * @index: index in linked list of where to insert PWD env var
 * Return: true on success, false on failure
 */
_Bool update_cur_dir(config *build, int index)
{
	static char tmp[BUFSIZE], cwd[BUFSIZE];

	getcwd(tmp, BUFSIZE);
	_strcat(cwd, "PWD=");
	_strcat(cwd, tmp);
	if (index > -1)
	{
		delete_node_at_index(&build->env, index);
		add_node_at_index(&build->env, index, cwd);
	}
	else
		add_node_at_index(&build->env, 0, cwd);
	get_null_bytes(tmp, 0);
	get_null_bytes(cwd, 0);
	return (true);
}
