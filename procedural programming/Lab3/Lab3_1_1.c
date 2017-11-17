/* Task 4 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	float x, y;

	printf("Enter x and y coords: ");
	if (scanf("%f %f", &x, &y) != 2)
	{
		printf("Error: invalid input. Exiting\n");
		return 1;
	}

	if ((y > 0 && x > 0 && sqrt(x * x + y * y) < 1) || (y > 0 && x < 0 && sqrt(x * x + y * y) > 1) || (y < 0 && x < 0 && y < x))
		printf("Point is inside of the area\n");
	else
		printf("Point is outside of the area\n");

	return 0;
}