/* Task 4 */

#include <stdio.h>
#include <math.h>

#define PI 3.14
#define E  2.7

int main(void)
{
	double a, x, y;

	printf("Enter x: ");
	if (scanf("%lf", &x) != 1)
	{
		printf("Error: invalid input. Exiting\n");
		return 1;
	}

	if (-PI / 2 < x && x < PI / 2)
	{
		printf("Using 1st branch\n");
		a = sin(x) - x * x;
	}
	else if (PI / 2 < x && x < 3)
	{
		printf("Using 2nd branch\n");
		a = cos(x) - pow(E, x);
	}
	else if (x > 3)
	{
		printf("Using 3rd branch\n");
		a = (x - 3) / (double)(x - 15);
	}
	else
	{
		printf("Incorrect x! Exiting\n");
		return 1;
	}
	
	if (x == 0.5)
	{
		printf("Error: division by zero. Exiting\n");
		return 1;
	}

	y = ((3 * a * x - pow(x, 3) + 1) / (x - 0.5));

	printf("Result: %lf\n", y);

	return 0;
}