#include <unistd.h>

char	ulstr(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	else if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}

int		main(int argc, char **argv)
{
	int i;
	char c;
	
	c = 0;
	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			c = ulstr(argv[1][i]);
			write(1, &c , 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
