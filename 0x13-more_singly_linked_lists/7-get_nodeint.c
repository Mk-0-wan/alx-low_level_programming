#include "lists.h"
#include <stdio.h>

/**
 * get_nodeint_at_index - retrive the node at a given index
 * @head: pointer to the first node element
 * @index: index of each element in the linked list
 * Return: pointer to the node at the given index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current;
	unsigned int i = 0;

	if (!head) /* check for empty list */
	{
		return (NULL);
	}
	current = head;
	while (i < index) /* move one step back then one ahead */
	{
		if (!current->next)
		{
			return (NULL);
		}
		current = current->next;
		i++;
	}
	return (current);
}
