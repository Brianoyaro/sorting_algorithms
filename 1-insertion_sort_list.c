#include "sort.h"
/**
 * insertion_sort_list - insertion sorts a list
 * @list: list to insertion sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *to_swap, *temp1, *temp2;
	int temp1_flag = 0, temp2_flag = 0;

	head = *list;
	if (head->next == NULL)
		return;
	while (head != NULL)
	{
		to_swap = head;
		head = head->next;
		if (to_swap->prev == NULL)
			to_swap = to_swap->next;
		while (to_swap->n < to_swap->prev->n)
		{
			if (to_swap->prev->prev != NULL)
			{
				temp1 = to_swap;
				temp1_flag = 1;
				to_swap->prev->next = to_swap->next;
				if (to_swap->next != NULL)
					to_swap->next->prev = to_swap->prev;
				to_swap->next = to_swap->prev;
				to_swap->prev = to_swap->prev->prev;
				to_swap->prev->next = to_swap;
				to_swap->next->prev = to_swap;
				print_list(*list);
			}
			if ((to_swap->prev->prev == NULL) && (to_swap->n < to_swap->prev->n))
			{
				temp2_flag = 1;
				temp2 = to_swap;
				to_swap->prev->next = to_swap->next;
				to_swap->next->prev = to_swap->prev;
				to_swap->prev->prev = to_swap;
				to_swap->next = to_swap->prev;
				to_swap->prev = NULL;
				*list = temp2;
				print_list(*list);
				break;
			}
		}
		if ((temp1_flag == 1 && temp2_flag == 1) || (temp1_flag == 1 && temp2_flag == 0))
			to_swap = temp1;
		if (temp2_flag == 1 && temp1_flag == 0)
			to_swap = temp2;
		to_swap = to_swap->next;
	}
}
