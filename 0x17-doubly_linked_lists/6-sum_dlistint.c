#include "lists.h"

/**
 * sum_dlistint - returns the total of all the data (n) of a dlistint_t list.
 * @point_l: pointer to the list.
 * Return: a sum of all data in the list, 0 if the lost is empty.
 **/
int sum_dlistint(dlistint_t *point_l)
{
	dlistint_t *anode = point_l;
	int total = 0;

	while (anode)
	{
		total += anode->n;
		anode = anode->next;
	}

	return (total);
}
