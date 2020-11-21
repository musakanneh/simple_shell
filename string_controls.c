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

