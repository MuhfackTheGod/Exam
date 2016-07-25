#include "ft_brainfuck.h"
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	make_operation(char *tab, char *av, int max)
{
	int	i;
	int j;
	i = 0;
	j = 0;
	while (av[i] != '\0' && i < max)
	{
		if (av[i] == '>')
		{
			tab++;
			i++;
		}
		if (av[i] == '<')
		{
			i++;
			tab--;
		}
		if (av[i] == '+')
		{
			tab[0] = tab[0] + 1;
			i++;
		}
		if (av[i] == '-')
		{
			tab[0] = tab[0] - 1;
			i++;
		}
		if (av[i] == '.')
		{
			write(1, &tab[0], 1);
			i++;
		}
		if (av[i] == '[')
		{
			while (av[i] != ']')
				j++;
			make_operation(tab, &av[i + 1], j);
			j = 0;
		}
		if (av[i] == ']' && tab[0] != 0)
		{
			i = 0;
		}
	}
}
void	brainfuck(char *av)
{
	char *tab;
	int	i;

	i = 0;
	tab = (char*)malloc(sizeof(char) * 2049);
	while (i <= 2048)
	{
		tab[i] = 0;
		i++;
	}
	tab[i] = '\0';
	make_operation(tab, av, ft_strlen(str));
}

int		main(int	ac, char **av)
{
	if (ac == 2)
		brainfuck(av[1]);
	else
		write(1, "\n", 1);
}
