#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

float convert_c_f(int c)
{
	return c * (9.0 / 5.0) + 32;
}

float convert_c_k(int c)
{
	return c + 273.15;
}

float convert_f_c(int f){
	return (f - 32) * (5.0 / 9.0);
}

float convert_k_c(int k){
	return k - 273.15;
}

float convert_k_f(int k){
	return k * (9.0 / 5.0) - 459.67;
}

float convert_f_k(int f){
	return (f + 459.67) * (5.0 / 9.0);
}

int is_temperature_correct(float t, char c)
{
	if (c == 'f')
	{
		if (t < -459.67)
		{
			printf("Temperature can't be below absolute zero!\n");
			return 0;
		}
	}
	else if (c == 'k')
	{
		if (t < 0)
		{
			printf("Temperature can't be below absolute zero!\n");
                        return 0;
		}
	}
	else  if (c == 'c')
	{
		if (t < -273.15)
		{
                        printf("Temperature can't be below absolute zero!\n");
                        return 0;
                }
	}
	else if (t < 0) // incorrect input (check highest temp  value)
	{
		printf("Temperature can't be below absolute zero!\n");
		return 0;
	}

	return 1;
}

int main()
{
	while (1)
	{
		char input_arr[100];
		int input_temp = 0;
		char input_scale = 'c';

		// max input len == 100
		fgets(input_arr, 100, stdin);

		// same as regex ^(-?\d+)
		input_temp = atoi(input_arr);

		// last char of array excluding \0
		input_scale = tolower(input_arr[strlen(input_arr) - 2]);

		printf("\nOUTPUT:\n");

		if (is_temperature_correct(input_temp, input_scale) != 1)
                	continue;

		if (input_scale == 'c')
		{
			printf("%.2f F\n", convert_c_f(input_temp));
			printf("%.2f K\n", convert_c_k(input_temp));
		}
		else if (input_scale == 'f')
		{
			printf("%.2f C\n", convert_f_c(input_temp));
			printf("%.2f K\n", convert_f_k(input_temp));
		}
		else if (input_scale == 'k')
		{
			printf("%.2f C\n", convert_k_c(input_temp));
			printf("%.2f F\n", convert_k_f(input_temp));
		}
		else
		{
			// convert using C
			printf("%d C:\n", input_temp);
			printf("%.2f F\n", convert_c_f(input_temp));
			printf("%.2f K\n", convert_c_k(input_temp));
			printf("\n");

			// convert using F
                        printf("%d F:\n", input_temp);
                        printf("%.2f C\n", convert_f_c(input_temp));
                        printf("%.2f K\n", convert_f_k(input_temp));
			printf("\n");

			// convert using K
                        printf("%d K:\n", input_temp);
                        printf("%.2f C\n", convert_k_c(input_temp));
                        printf("%.2f F\n", convert_k_f(input_temp));
			printf("\n");
		}
	}

	return 0;
}

