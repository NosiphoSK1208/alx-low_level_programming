#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list.
 * @point_l: pointer to the list.
 * Return: number of nodes.
 **/
size_t dlistint_len(const dlistint_t *point_l)
{
	const dlistint_t *nd = point_l;
	size_t cal = 0;

	while (nd)
	{
		cal++;
		nd = nd->next;
	}

	return (cal);
}
