#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list.
 * @point_l: pointer to the list.
 * Return: number of nodes.
 **/
size_t print_dlistint(const dlistint_t *point_l)
{
	const dlistint_t *node = point_l;
	size_t cal = 0;

	while (node)
	{
		printf("%i\n", node->n);
		cal++;
		node = node->next;
	}

	return (cal);
}
