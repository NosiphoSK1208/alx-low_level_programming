#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node node at a given position
 * in a dlistint_t list.
 * @point_l: pointer to the list.
 * @ind: position to add the node.
 * @n: data for the new node.
 * Return: the address of the new node, or NULL if it failed
 **/
dlistint_t *insert_dnodeint_at_index(dlistint_t **point_l, unsigned int ind, int n)
{
	dlistint_t *auxnode = *point_l, *anode;
	unsigned int mark, cal = 0;

	/* create node */
	anode = malloc(sizeof(dlistint_t));
	if (anode == NULL)
		return (NULL);
	anode->n = n;

	/* border case for insert at the beginning */
	if (ind == 0)
	{
		anode->prev = NULL;
		anode->next = *point_l;
		if (*point_l)
			(*point_l)->prev = anode;
		*point_l = anode;
		return (*point_l);
	}

	/* search of position to insert */
	mark = ind - 1;
	while (auxnode && cal != mark)
	{
		cal++;
		auxnode = auxnode->next;
	}

	/* general case */
	if (cal == mark && auxnode)
	{
		anode->prev = auxnode;
		anode->next = auxnode->next;
		if (auxnode->next)
			auxnode->next->prev = anode;
		auxnode->next = anode;
		return (anode);
	}
	free(anode);
	return (NULL);
}
