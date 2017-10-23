#include <stdio.h>

const char *bin_to_s(int);

int main(void)
{
	int a    = 0b10100111;
	int b    = 0;
	int mask = 1;

	printf("a: %s\n", bin_to_s(a));

	int i;
	for (i = 0; i < 8; i++)
	{
		if   (i < 4) b |= (a & (mask << i)) << (7 - i * 2);
		else         b |= (a & (mask << i)) >> (i * 2 - 7);
	}

	printf("b: %s\n", bin_to_s(b));

	return 0;
}

const char *bin_to_s(int num)
{
	const  int  num_size = 8;
	static char s[num_size + 1];
	int         i;

	for (i = 0; i < num_size; i++)
		s[i] = ((num >> (num_size - i - 1) & 1) == 0)? '0': '1';

	s[num_size] = '\0';

	return s;
}
