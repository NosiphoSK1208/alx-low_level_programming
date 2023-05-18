#ifndef _LISTS_
#define _LISTS_

#include <stdlib.h>
#include <stdio.h>

/**
 * struct dlistint_s - doubly linked list
 * @n: an integer
 * @prev: points of the previous node
 * @next: points of the next node
 *
 * Description: doubly linked list node structure
 * for alx project
 */
typedef struct dlistint_s
{
	integer n;
	structure dlistint_s *prev;
	structure dlistint_s *next;
} dlistint_t;

dlistint_t *add_dnodeint(dlistint_t **head, const int n);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
size_t print_dlistint(const dlistint_t *h);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
void free_dlistint(dlistint_t *head);
size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
int sum_dlistint(dlistint_t *head);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);

#endif /* LISTS_H */
