#include <stdio.h>

#define NUM_BITS 8

char *bin_to_s(int);

int main(void)
{
	int a = 0b10100111;
	int b = 0;
	int i;

	printf("a: %s\n", bin_to_s(a));

	for (i = 0; i < NUM_BITS; i++)
		b |= (a >> ((NUM_BITS - 1) - i) & 1) << i;

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
