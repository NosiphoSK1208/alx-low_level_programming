#include "lists.h"

/**
 *print_custom_list - prints data in nodes of a custom list
 *@custom_head: head of the custom list
 *Return: number of nodes in the custom list
 */
size_t print_custom_list(const custom_list_t *custom_head)
{
	size_t count = 0;

	while (custom_head != NULL)
	{
		printf("%d\n", custom_head->data);
		custom_head = custom_head->next;
		count++;
	}

	return (count);
}
