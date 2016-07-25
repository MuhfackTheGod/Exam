#include "ft_brainfuck.h"
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	make_operation(char *tab, char *av)
{
	int	i;
	int	j;
	int	len;
	int k;
	int	m;
	int	n;
	int o;

	n = 0;
	o = 0;
	m = 0;
	k = 0;
	i = 0;
	j = 0;
	len = ft_strlen(av);
	while (av[i] != '\0' && i < 4096)
	{
		if (av[i] == '>')
			tab++;
		if (av[i] == '<')
			tab--;
		if (av[i] == '+')
			tab[0] = tab[0] + 1;
		if (av[i] == '-')
			tab[0] = tab[0] - 1;
		if (av[i] == '.')
			write(1, &tab[0], 1);
		if (av[i] == '[')
		{
			j++;
			if (tab[0] == 0)
			{
				k = len - 1;
				while (j != m)
				{
					k--;
					if (av[k] == ']')
						m++;
				}
				i = k;
				j--;
			}
		}
		if (av[i] == ']')
		{
			n++;
			if (tab[0] != 0)
			{
				k = -1;
				while (n != o)
				{
					k++;
					if (av[k] == '[')
						o++;
				}
				n--;
				i = k;
			}
		}
		i++;
		k = 0;
		m = 0;
		o = 0;
	}
}
void	brainfuck(char *av)
{
	char *tab;
	int	i;

	i = 0;
	tab = (char*)malloc(sizeof(char) * 2048);
	while (i <= 2048)
	{
		tab[i] = 0;
		i++;
	}
	make_operation(tab, av);
}

int		main(int	ac, char **av)
{
	if (ac == 2)
		brainfuck(av[1]);
	else
		write(1, "\n", 1);
}
