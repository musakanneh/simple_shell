#include "holberton.h"

/**
 * find_built_ins - validates if command is builtin and executes
 * @build: input build
 * Return: true if found, false if not
 */
_Bool find_built_ins(config *build)
{
	register int i = 0;

	type_b get_built_ins[] = {
		{"exit", exit_function},
		{"env", env_function},
		{"history", historyFunc},
		{"alias", aliasFunc},
		{"cd", implement_cd},
		{"setenv", setenvFunc},
		{"unsetenv", unsetenvFunc},
		{"help", help_function},
		{NULL, NULL}};

	while (get_built_ins[i].command)
	{
		if (_strcmp(build->args[0], get_built_ins[i].command) == 0)
		{
			get_built_ins[i].func(build);
			free_args_and_buffer(build);
			return (true);
		}
		i++;
	}
	return (false);
}

/**
 * exitFunc - exits the application
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int exit_function(config *build)
{
	register int arg_count, exit_status;

	arg_count = count_args(build->args);
	if (arg_count == 1)
	{
		free_member(build);
		if (build->error_status)
		{
			exit(build->error_status);
		}
		exit(EXIT_SUCCESS);
	}
	else if (arg_count > 1)
	{
		exit_status = _atoi(build->args[1]);
		if (exit_status == -1)
		{
			errno = EILLEGAL;
			build->error_status = 2;
			handle_errors(build);
			return (0);
		}
		free_member(build);
		exit(exit_status);
	}
	return (1);
}

/**
 * historyFunc - displays command history
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int historyFunc(config *build)
{
	char *str = "Currently in development\n";

	(void)build;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * aliasFunc - displays local aliases
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int aliasFunc(config *build)
{
	char *str = "Currently in development\n";
	
	(void)build;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}
