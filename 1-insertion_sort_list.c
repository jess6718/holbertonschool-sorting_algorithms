#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list with insertion sort
 * @list: double pointers to the doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *next;
	/*if list is empty or elements of list are less than two*/
	if (list == NULL || (*list)->next == NULL)
		return;
	cur = *list;
	while (cur != NULL)
	{
		next = cur->next;
		/*enter loop when left node bigger than current & not first node*/
		while (cur->prev != NULL && cur->n < cur->prev->n)
		{
			if (cur->next != NULL)/*when current not point to last node of list*/
			{
				cur->next->prev = cur->prev;
			}
			cur->prev->next = cur->next;
			cur->next = cur->prev;
			cur->prev = cur->prev->prev;
			cur->next->prev = cur;

			if (cur->prev == NULL)
			{
				*list = cur;
			}
			else
			{
				cur->prev->next = cur;
			}
			print_list(*list);
		}
		cur = next;
	}
}
