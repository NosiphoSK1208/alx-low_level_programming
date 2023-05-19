#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @point_l: pointer to the list.
 * @mark: nth node.
 * Return: nth node, if the node doesn't exist, returns NULL.
 **/
dlistint_t *get_dnodeint_at_index(dlistint_t *point_l, unsigned int mark)
{
	dlistint_t *node = point_l;
	unsigned int cal = 0;

	while (node && cal != mark)
	{
		cal++;
		node = node->next;
	}
	if (node && cal == mark)
		return (node);
	return (NULL);
}
