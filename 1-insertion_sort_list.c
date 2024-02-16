#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;
	while (current != NULL)
	{
		listint_t *prev = current->prev;

		while (prev != NULL && current->n < prev->n)
		{
			if (current->next != NULL)
			{
				current->next->prev = prev;
			}
			prev->next = current->next;
			current->prev = prev->prev;
			if (prev->prev != NULL)
			{
				prev->prev->next = current;
			}
			else
			{
				*list = current;
			}
			prev->prev = current;
			current->next = prev;

			print_list(*list);

			prev = current->prev;
		}

		current = current->next;
	}
}
