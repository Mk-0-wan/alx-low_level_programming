#include "lists.h"
#include <stdio.h>


/**
 * print_list - prints all the values int the linked list
 * @h: pointer to the first node in the linked list
 * Return: number of nodes int the linked list.
 */
size_t print_list(const list_t *h)
{
	unsigned int count = 0, len;
	list_t *current = (list_t *)h;

	if (!h)
		return (-1);

	while (current != NULL)
	{
		len = current->len;
		if (!current->str)
		{
			current->str = "(nil)";
			len = 0;
		}
		printf("[%u] %s\n", len, current->str);
		current = current->next;
		count++;
	}
	return (count);
}

/**
 * _puts - output the strings to the stdio
 * @s: pointer to a string of chars
 * Return: void
 */
void _puts(char *s)
{
	int i = 0;

	for (; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
}