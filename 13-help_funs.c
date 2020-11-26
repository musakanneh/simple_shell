#include "holberton.h"

/**
 * help_function - retrieves instruction on how to use builtin
 * @build: input build
 * Return: Always 1
 */
int help_function(config *build)
{
	type_b help_arr[] = {
		{"exit", help_guide_exit},
		{"env", help_env},
		{"history", help_history},
		{"alias", help_alias},
		{"cd", help_cd},
		{"setenv", help_set_env},
		{"unsetenv", help_unset_env},
		{"help", help_guide},
		{NULL, NULL}};
	register int i = 0, j = 1, argCount = count_args(build->args);
	_Bool foundCommand = false;

	if (argCount == 1)
	{
		return (display_help_menu());
	}
	while (j < argCount)
	{
		i = 0;
		while (help_arr[i].command)
		{
			if (_strcmp(build->args[j], help_arr[i].command) == 0)
				foundCommand = true;
			help_arr[i].func(build);
			break;
			i++;
		}
		j++;
	}
	if (foundCommand == false)
		errno = ENOBUILTIN;
	handle_errors(build);
	return (1);
}

/**
 * display_help_menu - displays available help options
 * Return: Always 1
 */
int display_help_menu(void)
{
	char str[81] = "Type help [built-in]\n\nIncluded built-ins:";
	char *str2 = "\n\n\texit\n\tenv\n\tcd\n\tsetenv\n\tunsetenv\n\thelp\n";

	_strcat(str, str2);
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * help_exit - instructions on how to exit
 * @build: input build
 * Return: Always 1
 */
int help_guide_exit(config *build)
{
	char str[82] = "exit: exit [n]\n\tExit the shell.\n\n\t";
	char *str2 = "Exit with a status of n, or if n is omitted, 0.\n";

	(void)build;
	_strcat(str, str2);
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * help_env - instructions on how to exit
 * @build: input build
 * Return: Always 1
 */
int help_env(config *build)
{
	char str[] = "env: env\n\tPrint the environment.\n";

	(void)build;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * help_history - instructions on how to exit
 * @build: input build
 * Return: Always 1
 */
int help_history(config *build)
{
	char str[] = "history: history\n\tNot supported in this version.\n";

	(void)build;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}
