#include "holberton.h"

/**
 * splitString - splits string into an array of strings
 * separated by spaces
 * @build: input build
 *
 * Description: Gets the input string,
 * then breaks it into individual tokens and
 * store it in an array ans separately to implement them
 * Return: true if able to split, false if not
 */
_Bool split_string(config *build)
{
	register unsigned int i = 0;
	char *tok, *cpy;

	cpy = _strdup(build->buffer);
	tok = _strtok(cpy, " ");
	if (count_words(build->buffer) == 0)
	{
		build->args = NULL;
		free(build->buffer);
		return (false);
	}
	build->args = malloc((count_words(build->buffer) + 1) * sizeof(char *));
	while (tok)
	{
		build->args[i] = _strdup(tok);
		tok = _strtok(NULL, " ");
		i++;
	}
	build->args[i] = NULL;
	free(cpy);

	return (true);
}

/**
 * count_words - count number of words in a string
 * @str: input string
 *
 * Description: gets letters in ever word, checks for
 * empty spaces constraints and returns the word's total count
 * Return: number of words
 */
unsigned int count_words(char *str)
{
	register int words = 0;
	_Bool word_on = false;

	while (*str)
	{
		if (is_space(*str) && word_on)
		{
			word_on = false;
		}
		else if (!is_space(*str) && !word_on)
		{
			word_on = true;
			words++;
		}
		str++;
	}
	return (words);
}

/**
 * is_space - determines if char is a space
 * @c: input char
 * Return: true or false
 */
_Bool is_space(char c)
{
	return (c == ' ');
}
