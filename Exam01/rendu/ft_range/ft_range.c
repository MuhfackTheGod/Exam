#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int *tab;
	int	i;

	i = 0;

	if (end < start)
	{
		tab = (int*)malloc(sizeof(int) * (1 + start - end));
		while (start >= end)
		{
			tab[i] = start;
			start--;
			i++;
		}
	}
	else if (end > start)
	{
		tab = (int*)malloc(sizeof(int) * (1 + end - start));
		while (start <= end)
		{
			tab[i] = start;
			start++;
			i++;
		}

	}
	else if (end == start)
	{
		tab = (int*)malloc(sizeof(int));
		tab[i] = start;
	}
	return (tab);
}
