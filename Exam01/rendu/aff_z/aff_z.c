#include <unistd.h>

int		main(int argc, char **argv)
{
	char	str;

	write(1, "z\n", 2);
	str = argv[0][0];
	return (argc);
}
