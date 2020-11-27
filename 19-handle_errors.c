#include "holberton.h"

/**
 * handle_errors - a function that handles wrong user inputs
 * @build: build input params
 *
 * Description: accepts user inputs and tests them
 * handles constraints like: concatenations,
 * converting strings to int etc.
 * Return: Nothing
 */
void handle_errors(config *build)
{
	register int len;
	static char error[BUFSIZE];
	char *ptr, *is_alpha;

	is_alpha = itoa(build->count_line);
	_strcat(error, build->shell_name);
	_strcat(error, ": ");
	_strcat(error, is_alpha);
	_strcat(error, ": ");
	_strcat(error, build->args[0]);
	_strcat(error, get_error_message());
	if (build->args[1])
	{
		if (errno != EBADCD)
		{
			_strcat(error, ": ");
		}
		_strcat(error, build->args[1]);
	}
	_strcat(error, "\n");
	ptr = _strchr(error, '\n');
	len = ptr - error;
	write(STDERR_FILENO, error, len + 1);
	free(is_alpha);
	get_null_bytes(error, 0);
}

/**
 * get_error_message - matches errno to corresponding string
 * Return: string of error message
 */
char *get_error_message(void)
{
	char *str;

	switch (errno)
	{
	case EBADCD:
		str = ": Can't cd to ";
		break;
	case ENOENT:
		str = ": Not found";
		break;
	case ENOSTRING:
		str = ": Bad variable name (s)";
		break;
	case EILLEGAL:
		str = ": Illegal number";
		break;
	case EWSIZE:
		str = ": Invalid number of arguments";
		break;
	case ENOBUILTIN:
		str = ": type help for a list of built-ins";
		break;
	case EACCES:
		str = ": Permission denied";
		break;
	default:
		str = ": No error number assigned";
	}
	return (str);
}

/**
 * count_num_digits - count number of digits in a number
 * @num: input number
 * Return: number of digits
 */
unsigned int count_num_digits(int num)
{
	register int digits = 0;

	while (num > 0)
	{
		digits++;
		num /= 10;
	}
	return (digits);
}

/**
 * itoa - converts integer to string
 * @num: input integer
 * Return: string type of number
 */
char *itoa(unsigned int num)
{
	register int digits = 0;
	char *str;

	digits += count_num_digits(num);
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
	{
		perror("Malloc: failed\n");
		exit(errno);
	}
	get_null_bytes(str, digits);
	while (num > 0)
	{
		str[digits - 1] = num % 10 + '0';
		num = num / 10;
		digits--;
	}
	free(str);
	return (str);
}
