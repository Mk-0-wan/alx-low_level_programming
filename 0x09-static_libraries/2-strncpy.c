#include "main.h"
/**
 * _strncpy - copy a string
 * @dest: pointer to where to copy to
 * @src: what to copy over
 * @n: number of chars to copy
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j;

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}

	return (dest);
}
