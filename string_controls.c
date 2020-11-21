#include "holberton.h"

/**
 * _strcat - concat two strings
 * @str1: first parameter
 * @str2: second parameter
 * 
 * Descritption - concat strings
 * Return: char
 */

char *_strcat(char *str1, char *str2)
{
	int str1_len, str2_len, i = 0, j = 0;
	char *conc;

	str1_len = _strlen(str1);
	str2_len = _strlen(str2);
	conc = malloc(str1_len + str2_len + 2);

	if (!conc)
		return (NULL);

	*conc = '\0';

	while (str1[j])
		conc[i++] = str1[j++];

	conc[i++] = '/';

	j = 0;

	while (str2[j])
		conc[i++] = str2[j++];

	conc[i] = '\0';
	return (conc);
}

/**
 * _strlen - get lenght of a string
 * @s: first parameter
 *
 * Description - get lenght of a string
 * Return: lenght
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i];)
		i++;
	
	return (i);
}

/**
 * _strcpy - copies the content of a string to another
 * @dest: first parameter
 * @src: second parameter
 *
 * Description - copies the contents of a string to another
 * Return: string
*/

char *_strcpy(char *dest, char *src)
{
	char *res = dest;

	if ((dest != '\0') && (src != '\0'))
	{
		while (*src != '\0')
			*dest++ = *src++;
		*dest = '\0';
	}
	return (res);
}

/**
 * _strcmp - compares content of a string
 * @s1: first parameter
 * @s2: second parameter
 * 
 * Description - compares contents of a string
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
		return (*s1 - *s2);
}

/**
 * _strdup - duplicates a string
 * @str: first parameter
 * 
 * Description - duplicates a string
 * Return: pointer type char
 */

char *_strdup(char *str)
{
	int i = 0;
	char *ing;
	char *temp;

	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	ing = malloc(i + 1);
	temp = ing;
	if (ing == NULL)
		return (NULL);
	while (*str)
		*temp++ = *str++;
	*temp = '\0';
	return (ing);
}

/**
 * itoa - convert integer to string
 * @n: first parameter
 *
 * Description - converts integer to string
 * Return: a pointer to the null terminated string
 */
char *itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	rev_arr(s, len);
	s[i + 1] = '\0';
	return (s);
}
