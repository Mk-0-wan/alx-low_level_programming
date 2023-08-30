#include "main.h"
/**
 * _print_rev_recursion - reverse recursion
 * @s: pointer to a string
 * Return: void
 */
void _print_rev_recursion(char *s)
{
	if (!s) /* exit point */
		return;
	_print_rev_recursion(s + 1); /* move to the next pointer */
	_putchar(*s); /* start printing the  chars */
}
