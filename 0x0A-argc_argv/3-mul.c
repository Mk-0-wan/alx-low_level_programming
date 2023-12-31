#include "main.h"
#include <stdio.h>
/**
 * _atoi - converting string to int
 * @s: pointer to a string
 * Return: converted value or 0 on error
 */
int _atoi(char *s)
{
	int sign = 1, i = 0;
	unsigned int result = 0;

	/* look for all the negative values inside the string */
	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	/* look for all the non-negative values inside the string */
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	result *= sign;
	return (result);
}

/**
 * main - multiple of two arguments
 * @argc: argument count
 * @argv: list of arguments passed
 * Return: 0 success 1 error
 */
int main(int argc, char *argv[])
{
	int x = 0, y = 0, result = 0;

	if (argc < 3 || argc > 3)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		x = _atoi(argv[1]);
		y = _atoi(argv[2]);
		result = (x * y);
		printf("%d\n", result);
	}
	return (0);
}
