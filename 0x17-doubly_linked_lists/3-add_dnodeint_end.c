#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @point_l: pointer to the first element of the list.
 * @n: int to set in the new node.
 * Return: address of the new element, or NULL if it failed
 **/
dlistint_t *add_dnodeint_end(dlistint_t **point_l, const int n)
{
	dlistint_t *anew, *xa = *point_l;

	anew = malloc(sizeof(dlistint_t));
	if (anew == NULL)
		return (NULL);
	anew->n = n;
	anew->next = NULL;

	if (xa)
	{
		while (xa->next)
			xa = xa->next;
		anew->prev = xa;
		xa->next = anew;
	}
	else
	{
		*point_l = anew;
		anew->prev = NULL;
	}

	return (anew);
}
