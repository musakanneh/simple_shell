#include "holberton.h"

/**
 * shell - a function that executes the
 * loop's functionalities
 * @build: input build params
 *
 * Description: reviews user inputs and validates strings;
 * otherwise, check the path, forkand execute it
 * Return: Nothing
 */
void shell(config *build)
{
	while (1)
	{
		validate_line(build);
		if (split_string(build) == 0)
		{
			continue;
		}
		if (find_built_ins(build) == 1)
		{
			continue;
		}
		check_path(build);
		fork_and_execute(build);
	}
}

/**
 * validate_line - a function to handle the user inputs
 *
 * Description: gets user inputs, checks input against
 * build constraints, string edge cases and takes endless inputs
 * @build: input build params
 * Return: Nothing
 */
void validate_line(config *build)
{
	register int len;
	size_t buffer_size = 0;
	char *ptr, *ptr2;

	build->args = NULL;
	build->env_list = NULL;
	build->count_line++;
	if (isatty(STDIN_FILENO))
	{
		get_prompt();
	}
	len = getline(&build->buffer, &buffer_size, stdin);
	if (len == EOF)
	{
		/* checks relation with terminal device */
		if (isatty(STDIN_FILENO))
		{
			put_new_line();
		}
		if (build->error_status)
		{
			exit(build->error_status);
		}
		exit(EXIT_SUCCESS);
	}
	ptr = _strchr(build->buffer, '\n');
	ptr2 = _strchr(build->buffer, '\t');
	if (ptr || ptr2 != NULL)
	{
		get_null_bytes(build->buffer, len - 1);
	}
	strip_comments(build->buffer);
}

/**
 * strip_comments - remove comments from input string
 * @str: input string
 * Return: length of remaining string
 */
void strip_comments(char *str)
{
	register int i = 0;
	_Bool is_not_first = false;

	while (str[i])
	{
		if (i == 0 && str[i] == '#')
		{
			get_null_bytes(str, i);
			return;
		}
		if (is_not_first)
		{
			if (str[i] == '#' && str[i - 1] == ' ')
			{
				get_null_bytes(str, i);
				return;
			}
		}
		i++;
		is_not_first = true;
	}
}

/**
 * fork_and_execute - fork current build and execute processes
 *
 * Description: forks executing processes, then run the bin/ls program
 * in child process, using the execve syscall.
 * @build: input build
 * Return: Nothing
 */
void fork_and_execute(config *build)
{
	int status;
	pid_t f1 = fork();

	convert_llist_to_arr(build);
	if (f1 == -1)
	{
		perror("error\n");
		free_member(build);
		free_args(build->env_list);
		exit(1);
	}
	if (f1 == 0)
	{
		if (execve(build->full_path, build->args, build->env_list) == -1)
		{
			handle_errors(build);
			free_member(build);
			free_args(build->env_list);
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
		{
			build->error_status = WEXITSTATUS(status);
		}
		free_args_and_buffer(build);
		free_args(build->env_list);
	}
}

/**
 * convert_llist_to_arr - convert linked list to array
 * @build: input build params
 */
void convert_llist_to_arr(config *build)
{
	register int i = 0;
	size_t count = 0;
	char **env_list = NULL;
	linked_l *tmp = build->env;

	count = list_len(build->env);
	env_list = malloc(sizeof(char *) * (count + 1));

	if (!env_list)
	{
		perror("Malloc failed\n");
		exit(1);
	}
	while (tmp)
	{
		env_list[i] = _strdup(tmp->string);
		tmp = tmp->next;
		i++;
	}
	env_list[i] = NULL;
	build->env_list = env_list;
	free(env_list);
}
