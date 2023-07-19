#include "function_pointer.h"
#include <stdio.h>
/**
 * array_iterator - print elements
 * @array: array
 * @size: no of element
 * @action: pointer to print
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
