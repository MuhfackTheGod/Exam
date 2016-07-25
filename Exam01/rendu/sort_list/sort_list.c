#include "list.h"
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *current;
	t_list *next;
	int	tmp;
	int	is_sort;

	tmp = 0;
	is_sort = 0;
	current = lst;
	next = current->next;
	while (is_sort == 0)
	{
		current = lst;
		next = current->next;
		is_sort = 1;
		while (next && current)
		{
			if (cmp(current->data, next->data) == 0)
			{
				tmp = current->data;
				current->data = next->data;
				next->data = tmp;
				is_sort = 0;
			}
			current = current->next;
			next = next->next;
		}
	}
	return (lst);
}
