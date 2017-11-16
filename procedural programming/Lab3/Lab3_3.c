/* Task 4 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	float x, y;
	char choice, condition;

	printf("Enter x and y coords: ");
	if (scanf("%f %f", &x, &y) != 2)
	{
		printf("Error: invalid input. Exiting");
		return 1;
	}
	getchar();

	printf("Please, select program algorithm by entering number:\n");
	printf("1: if with condition\n");
	printf("2: if with condition-variable\n");
	printf("3: using \"?\" operation\n");
	printf("> ");

	scanf("%d", &choice);
	switch (choice)
	{
		case 1:
			if ((y > 0 && x > 0 && sqrt(x * x + y * y) < 1) || (y > 0 && x < 0 && sqrt(x * x + y * y) > 1) || (y < 0 && x < 0 && y < x))
				printf("Point is inside of the area\n");
			else
				printf("Point is outside of the area\n");
			break;
		case 2:
			condition = (y > 0 && x > 0 && sqrt(x * x + y * y) < 1) || (y > 0 && x < 0 && sqrt(x * x + y * y) > 1) || (y < 0 && x < 0 && y < x);

			if (condition)
				printf("Point is inside of the area\n");
			else
				printf("Point is outside of the area\n");
			break;
		case 3:
			printf("Point is %sside of the area\n", (y > 0 && x > 0 && sqrt(x*x + y*y) < 1) || (y > 0 && x < 0 && sqrt(x*x + y*y) > 1) || (y < 0 && x < 0 && y < x) ? "in" : "out");
			break;
		default:
			printf("Wrong choice\n");
	}
	
	return 0;
}