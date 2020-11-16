#include "holberton.h"

/**
 * _shell - a function that executes the loop functionalities
 * Return: Nothing
 */
void shell(config *build)
{
	while (1)
	{
		checkAndGetLine(build);
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
		displayPrompt();
	}
	len = getline(&build->buffer, &buffer_size, stdin);
	if (len == EOF)
	{
		_free(build);
		if (isatty(STDIN_FILENO))
		{
			displayNewLine();
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
		insertNullByte(build->buffer, len - 1);
	}
	stripComments(build->buffer);
}