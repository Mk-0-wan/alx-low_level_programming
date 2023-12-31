#include "lists.h"
#include <complex.h>
/**
 * create_node - initialize a new node
 * @data: value to hold in the node
 * Return: pointer pointer to the new node
 */
dlistint_t *create_node(int data)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (!new_node)
		return (NULL);

	new_node->n = data;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}
/**
 * insert_dnodeint_at_index - insert a node at a given index
 * @h: pointer to the first node of the list
 * @idx: insert node at that index
 * @n: node new value
 * Return: pointer to the new node inserted
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current = *h;
	dlistint_t *inset_node = NULL;
	unsigned int iter = 1;

	inset_node = create_node(n);

	if (!*h || !h)
		return (inset_node);

	if (idx == 0)
	{
		inset_node->next = *h;
		if (*h)
			(*h)->prev = inset_node;
		*h = inset_node;
		return (inset_node);
	}
	while (current)
	{
		if (iter == idx)
		{
			if (!current->next)
			{
				current->next = inset_node;
				inset_node->prev = current;
			}
			else
			{
				inset_node->next = current->next;
				current->next = inset_node;
				current->next->prev = inset_node;
				inset_node->prev = current;
			}
			return (inset_node);
		}
		current = current->next;
		iter++;
	}
	free(inset_node);
	return (NULL);
}
