unsigned char	swap_bits(unsigned char a)
{
	unsigned char	b;

	b = a;
	a = a << 4;
	b = b >> 4;
	return (a | b);
}
