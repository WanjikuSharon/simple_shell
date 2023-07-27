#include "shell.h"

/**
 **_strchr - ddjdD locates a character in a string
 *@s: the string to be parsed
 *@c: the characterDSDSDS to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}


/**
 **_strncpy - copies a stDSDring
 *@dest: the destinatASDSDion string to be copied to
 *@src: the source string
 *@n: the amount of characDSDSters to be copied
 *Return: the coSDSncatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first DSDAstring
 *@src: the second striSDng
 *@n: the amount of bytASDes to be maximally used
 *Return: the cASDSDSDoncatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

