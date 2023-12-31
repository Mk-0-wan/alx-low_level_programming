#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
/**
 * _strlen - return the length of an array
 * @s: array of chars
 * Return: number of chars in a string
 */
int _strlen(char *s)
{
	size_t len = 0;

	while (s && s[len])
	{
		len++;
	}
	return (len);
}
/**
 * _strcpy - a copied string of chars
 * @copy: pointer to the new copied string
 * @original: pointer to the original string
 * Return: pointer to the newly copied string
 */
char *_strcpy(char *copy, char *original)
{
	unsigned int i = 0;

	while (original[i] != '\0')
	{
		copy[i] = original[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/**
 * new_dog - creates a new object from the data structure
 * @name: string of chars that represents the name of the dog
 * @age: float integer representing the dog's age
 * @owner: string of chars representing the owner's name
 * Return: a new data structure with new object
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *obj_holder;

	obj_holder = malloc(sizeof(dog_t));
	if (!obj_holder)
		return (NULL);

	obj_holder->name = name;
	if (name)
	{
		obj_holder->name = malloc(sizeof(char) * (_strlen(name) + 1));
		if (!obj_holder->name)
			return (NULL);
		obj_holder->name = _strcpy(obj_holder->name, name);
	}
	else
	{
		free(obj_holder);
		return (NULL);
	}
	obj_holder->age = age;
	obj_holder->owner = owner;
	if (owner)
	{
		obj_holder->owner = malloc(sizeof(char) * (_strlen(owner) + 1));
		if (!obj_holder->owner)
			return (NULL);
		obj_holder->owner = _strcpy(obj_holder->owner, owner);
	}
	else
	{
		free(obj_holder->name);
		free(obj_holder);
		return (NULL);
	}
	return (obj_holder);
}
