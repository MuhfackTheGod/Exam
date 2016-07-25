#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	match(char find, char *check)
{
	int 	i;

	i = 0;
	while (check[i] != '\0')
	{
		if (find == check[i])
			return(0);
		i++;
	}
	return (1);
}

void	union_ex_bis(char *find, char *search)
{
	int	i;
	int	j;
	int 	check;

	i = 0; 
	j = i;
	check = 1;

	while (find[i] != '\0')
	{
		j = i;
		i = j - 1;
		check = 1;
		check = match(find[j], search);
		while (i >= 0)
		{
			if (find[i] == find [j])
				check = 0;
			i--;
		}
		if (check)
			write(1, &find[j], 1);
		i = j;
		i++;
	}

}

void	union_ex(char *find)
{
	int	i;
	int	j;
	int 	check;

	i = 0; 
	j = i;
	check = 1;

	while (find[j] != '\0')
	{
		check = 1;
		j = i;
		i = j - 1;
		while (i >= 0)
		{

			if (find[i] == find [j])
				check = 0;
			i--;
		}
		if (check)
		{
			if (find[j] != '\0')
				write(1, &find[j], 1);
		}
		i = j;
		i++;
	}

}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		union_ex(av[1]);
		union_ex_bis(av[2], av[1]);
	}
	write (1, "\n", 1);
}
