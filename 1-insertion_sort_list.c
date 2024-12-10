#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list: list to be sorted
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *curr = *list;
	listint_t *next;
	listint_t *curr_sorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	while (curr != NULL)
	{
		next = curr->next;
		if (sorted == NULL || sorted->n >= curr->n)
		{
			curr->next = sorted;
			if (sorted != NULL)
			{
				sorted->prev = curr;
			}
			curr->prev = NULL;
			sorted = curr;
		}
		else
		{
			curr_sorted = sorted;
			while (curr_sorted->next != NULL &&
					curr_sorted->next->n < curr->n)
			{
				curr_sorted = curr_sorted->next;
			}
			curr->next = curr_sorted->next;
			if (curr_sorted->next != NULL)
			{
				curr_sorted->next->prev = curr;
			}
			curr_sorted->next = curr;
			curr->prev = curr_sorted;
		}
		curr = next;
	}
	*list = sorted;
}
