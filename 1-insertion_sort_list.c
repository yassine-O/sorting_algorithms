#include "sort.h"

/**
 * insertion_sort_list - Entry point
 * @list: pointer
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp, *tmp_next, *tmp_prev;

	if (list == NULL)
		return;

	current = *list;
	while (current->next != NULL)
	{
		if (current->n <= current->next->n)
		{
			current = current->next;
			continue;
		}
		tmp = current->next;
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			tmp_prev = tmp->prev;
			tmp_next = tmp->next;

			tmp->prev = tmp_prev->prev;
			tmp->next = tmp_prev;

			if (tmp_prev->prev != NULL)
			{
				tmp_prev->prev->next = tmp;
			}
			else
			{
				*list = tmp;
			}

			tmp_prev->prev = tmp;
			tmp_prev->next = tmp_next;
			if (tmp_next != NULL)
				tmp_next->prev = tmp_prev;

			print_list(*list);
		}
	}
}
