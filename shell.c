#include "holberton.h"

/**
 * _shell - a function that executes the loop functionalities
 * Return: Nothing
 */
void shell(config *build)
{
	while (1)
	{
		validate_line(build);
		if (splitString(build) == 0)
		{
			continue;
		}
		if (findBuiltIns(build) == 1)
		{
			continue;
		}
		checkPath(build);
		forkAndExecute(build);
	}
}

/**
 * validate_line - a function to handle the prompts
 * Return: Nothing
 */
void validate_line(config *build)
{
	register int len;
	size_t buffer_size = 0;
	char *ptr, *ptr2;

	build->args = NULL;
	build->envList = NULL;
	build->lineCounter++;
	if (isatty(STDIN_FILENO))
	{
		get_prompt();
	}
	len = getline(&build->buffer, &buffer_size, stdin);
	if (len == EOF)
	{
		free(build);
		if (isatty(STDIN_FILENO))
		{
			put_new_line();
		}
		if (build->errorStatus)
		{
			exit(build->errorStatus);
		}
		exit(EXIT_SUCCESS);
	}
	ptr = _strchr(build->buffer, '\n');
	ptr2 = _strchr(build->buffer, '\t');
	if (ptr || ptr2)
	{
		get_null_bytes(build->buffer, len - 1);
	}
	strip_comments(build->buffer);
}

/**
 * stripComments - remove comments from input string
 * @str: input string
 * Return: length of remaining string
 */
void strip_comments(char *str)
{
	register int i = 0;
	_Bool notFirst = false;

	while (str[i])
	{
		if (i == 0 && str[i] == '#')
		{
			get_null_bytes(str, i);
			return;
		}
		if (notFirst)
		{
			if (str[i] == '#' && str[i - 1] == ' ')
			{
				get_null_bytes(str, i);
				return;
			}
		}
		i++;
		notFirst = true;
	}
}

/**
 * fork_and_execute - fork current build and execute processes
 * @build: input build
 */
void forkAndExecute(config *build)
{
	int status;
	pid_t f1 = fork();

	convertLLtoArr(build);
	if (f1 == -1)
	{
		perror("error\n");
		free_member(build);
		free_args(build->envList);
		exit(1);
	}
	if (f1 == 0)
	{
		if (execve(build->fullPath, build->args, build->envList) == -1)
		{
			handle_errors(build);
			free_member(build);
			free_args(build->envList);
			if (errno == ENOENT)
				exit(127);
			if (errno == EACCES)
				exit(126);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			build->errorStatus = WEXITSTATUS(status);
		free_args_and_buffer(build);
		free_args(build->envList);
	}
}

/**
 * convertLLtoArr - convert linked list to array
 * @build: input build
 */
void convertLLtoArr(config *build)
{
	register int i = 0;
	size_t count = 0;
	char **envList = NULL;
	linked_l *tmp = build->env;

	count = list_len(build->env);
	envList = malloc(sizeof(char *) * (count + 1));
	if (!envList)
	{
		perror("Malloc failed\n");
		exit(1);
	}
	while (tmp)
	{
		envList[i] = _strdup(tmp->string);
		tmp = tmp->next;
		i++;
	}
	envList[i] = NULL;
	build->envList = envList;
}