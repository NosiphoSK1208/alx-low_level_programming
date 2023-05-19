#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @ps: pointer to the list.
 **/
void free_dlistint(dlistint_t *ps)
{
	dlistint_t *c_node;
	dlistint_t *n_node;

	if (ps)
	{
		c_node = ps;
		n_node = ps->next;
		while (n_node)
		{
			free(c_node);
			c_node = n_node;
			n_node = n_node->next;
		}
		free(c_node);
	}
}
