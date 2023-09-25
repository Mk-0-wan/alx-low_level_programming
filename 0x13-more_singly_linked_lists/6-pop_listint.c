#include "lists.h"

/**
 * pop_listint - removes the head node
 * @head: pointer to the first node
 * Return: head node data (n)
 */
int pop_listint(listint_t **head)
{
	listint_t *new_node;
	int ret = 0;

	if (!*head)
	{
		return (0);
	}
	new_node = (*head)->next; /* store the next node */
	ret = (*head)->n; /* collect head node val */
	free(*head);
	*head = new_node; /* make new node the new head node */
	return (ret);
}
