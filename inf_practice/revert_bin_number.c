#include <stdio.h>

#define NUM_BITS 8

char *bin_to_s(int);

int main(void)
{
	int a    = 0b10100111;
	int b    = 0;
	int mask = 1;

	printf("a: %s\n", bin_to_s(a));

	int i;
	for (i = 0; i < NUM_BITS; i++)
	{
		if   (i < (NUM_BITS / 2))
			b |= (a & (mask << i)) << ((NUM_BITS - 1) - i * 2);
		else
			b |= (a & (mask << i)) >> (i * 2 - (NUM_BITS - 1));
	}

	printf("b: %s\n", bin_to_s(b));

	return 0;
}

char *bin_to_s(int num)
{
	static char s[NUM_BITS + 1];
	int i;

	for (i = 0; i < NUM_BITS; i++)
		s[i] = (num >> ((NUM_BITS - 1) - i) & 1)? '1': '0';

	s[NUM_BITS] = '\0';

	return s;
}
