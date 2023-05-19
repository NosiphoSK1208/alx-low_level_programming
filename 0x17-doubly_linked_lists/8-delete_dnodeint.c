#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at indx of a dlistint_t list.
 * @point_l: pointer to the list.
 * @indx: position of the node to delete.
 * Return: 1 if it succeeded, -1 if it failed.
 **/
int delete_dnodeint_at_index(dlistint_t **point_l, unsigned int indx)
{
	dlistint_t *anode = *point_l;
	dlistint_t *delete_node = *point_l;
	unsigned int ix;
	unsigned int cal = 0;

	/* border case for empty list */
	if (!(*point_l))
		return (-1);

	/* border case for delete at the beginning */
	if (indx == 0)
	{
		*point_l = delete_node->next;
		free(delete_node);
		if (*point_l)
			(*point_l)->prev = NULL;
		return (1);
	}

	/* search of position to delete */
	ix = indx - 1;
	while (anode && cal != ix)
	{
		cal++;
		anode = anode->next;
	}

	/* general case */
	if (cal == ix && anode)
	{
		delete_node = anode->next;
		if (delete_node->next)
		delete_node->next->prev = anode;
		anode->next = delete_node->next;
		free(delete_node);
		return (1);
	}

	return (-1);
}
