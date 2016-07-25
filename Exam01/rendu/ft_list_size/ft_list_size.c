#include "ft_list.h"
int	ft_list_size(t_list *begin_list)
{
	t_list *list;
	int	i;
	if (begin_list)
		i = 1;
	else 
	{
		i= 0;
		return (i);
	}
	list = begin_list;
	
	while (list->next)
	{
		list = list->next;
		i++;
	}
	return (i);
}
