#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @ahead: pointer to the first element of the list.
 * @n: int to set in the new node.
 * Return: address of the new element, or NULL if it failed
 **/
dlistint_t *add_dnodeint(dlistint_t **ahead, const int n)
{
	dlistint_t *anew;

	anew = malloc(sizeof(dlistint_t));
	if (anew == NULL)
		return (NULL);

	anew->n = n;
	anew->prev = NULL;
	anew->next = *ahead;
	if (*ahead)
		(*ahead)->prev = anew;
	*ahead = anew;

	return (anew);
}
