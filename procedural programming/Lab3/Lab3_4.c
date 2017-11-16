/* Task 4 */

#include <stdio.h>
#include <math.h>
#include <string.h>

#define NUM_TESTS 11
#define PI 3.14
#define E  2.7

#define DM1 "Incorrect x"
#define DM2 "Division by zero"

struct task_result {
	double result;
	char error_text[1024];
};

struct task_result task(double x);
int exec_test(int test_num);

int main(void)
{
	int i, n;
	char response = 'y';

	printf("Enter number of tests to execute: ");
	scanf("%d", &n);
	getchar();

	if (n > NUM_TESTS)
	{
		printf("Warning: too big numbre of tests entered. Only %d exists\n", NUM_TESTS);
		n = NUM_TESTS;
	}

	for (i = 0; i < n ; i++)
	{
		printf("Running test %d ...\n", i + 1);
		if (!exec_test(i))
		{
			printf("Test %d failed\n\n", i + 1);
			break;
		}
		else
			printf("Test %d success\n\n", i + 1);

		printf("Enter Y if you wan to continue\n>");
		if ((response = getchar()) != 'y' && response != 'Y')
			break;
		getchar();
	}

	printf("Have a nice day :)\n");

	return 0;
}

int exec_test(int index_of_test)
{
	double expected;
	struct task_result result;

	switch (index_of_test)
	{
		case 0:
			result = task(3);
			return strcmp(result.error_text, DM1) == 0;
		case 1:
			result = task(0.5);
			return strcmp(result.error_text, DM2) == 0;
		case 2:
			expected = -2;
			result   = task(0);
			break;
		case 3:
			expected = -2;
			result   = task(0);
			break;
		case 4:
			expected = -2;
			result   = task(1);
			break;
		case 5:
			expected = -2;
			result   = task(-0.5);
			break;
		case 6:
			expected = task(-0).result;
			result   = task(0);
			break;
		case 7:
			expected = task(2 * PI).result;
			result   = task(PI * 2);
			break;
		case 8:
			break;
		case 9:
			expected = -43.903072;
			result   = task(2 * PI);
			break;
		case 10:
			expected = -65.616223;
			result   = task(E);
			break;
		default:
			printf("Error: wrong test index recieved (%d)", index_of_test);
			return 0;
	}
	if (result.result == result.result)  // check NAN
		if (fabs(result.result - expected) < 0.00001)
			return 1;
		else
		{
			printf("Wrong result recieved: %lf\nExpected: %lf\n", result.result, expected);
			return 0;
		}

	printf("Error: %s\n", result.error_text);
	return 0;
}

struct task_result task(double x)
{
	struct task_result result;

	result.result = NAN;
	result.error_text[0] = '\0';

	double a;

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
		strcpy(result.error_text, DM1);
		return result;
	}

	if (x == 0.5)
	{
		strcpy(result.error_text, DM2);
		return result;
	}

	result.result = ((3 * a * x - pow(x, 3) + 1) / (x - 0.5));

	return result;
}