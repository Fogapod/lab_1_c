#include <stdio.h>

int main(void)
{
	int num, buffer, reversed;
	while (1)
	{
		printf("Enter number: ");
		if (scanf("%d", &num) != 1)
		{
			printf("Invalid input\n");
			break;
		}

		reversed = 0;
		buffer = (num < 0)? -num: num;

		while (num > 0)
		{
			reversed *= 10;
			reversed += num % 10;
			num /= 10;
		}

		printf("%s polindrome\n", (buffer != reversed)? "Not a": "Is a");
	}

	return 0;
}
