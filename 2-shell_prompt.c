#include "holberton.h"

/**
 * get_null_bytes - insert null bytes at a given index
 * @str: input string
 * @index: a space to contain  the null bytes
 * Return: Nothing
 */
void get_null_bytes(char *str, unsigned int index)
{
	str[index] = '\0';
}

/**
 * get_prompt - accepts users inputs
 * Return: Nothing
 */
void get_prompt(void)
{
	write(STDERR_FILENO, "$ ", 2);
}

/**
 * put_new_line - prints a newline
 * Return: Nothing
 */
void put_new_line(void)
{
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * handle_sigint - a function to handle singal integers
 * @sigint: signal input
 * Return: Nothing
 */
void handle_sigint(int sigint)
{
	(void)sigint;
	signal(SIGINT, handle_sigint);
	put_new_line();
	put_new_line();
	fflush(stdout);
}
