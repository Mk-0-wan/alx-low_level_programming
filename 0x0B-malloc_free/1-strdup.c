#include "main.h"
/**
 * _strdup - duplicates the string passed to it
 * @str: pointer to a string of chars
 * Return: a pointer to a newly duplicated string from the original.
 */
char *_strdup(char *str)
{
	char *cp_str = str;
	size_t len = 0, i = 0;

	if (!str)
		return (NULL);
	while (str[len])
		len++;

	cp_str = malloc((len + 1) * sizeof(char));
	MALLOC_CHECK(cp_str);

	while (i < len)
	{
		cp_str[i] = str[i]; /* copy over each char */
		i++;
	}
	cp_str[len] = '\0'; /* add a null terminator */
	return (cp_str);
}
