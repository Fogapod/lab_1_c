#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

float convert_c_f(int c){
	return 0;
}

float convert_c_k(int c){
	return 0;
}

float convert_f_c(int f){
	return 0;
}

float convert_k_c(int k){
	return 0;
}

float convert_k_f(int k){
	return 0;
}

float convert_f_k(int f){
	return 0;
}

int main(){
	while (1) {
		char input_arr[100];
		int input_temp = 0;
		char input_scale = 'c';
	
		fgets(input_arr, 100, stdin);

		input_temp = atoi(input_arr);

		if (tolower(input_arr[strlen(input_arr) - 2]) == 'c'){
			printf("%f F\n", convert_c_f(input_temp));
			printf("%f K\n", convert_c_k(input_temp));
		}
		else if (tolower(input_arr[strlen(input_arr) - 2]) == 'f'){
			printf("%f C\n", convert_f_c(input_temp));
			printf("%f K\n", convert_f_k(input_temp));
		}
		else if (tolower(input_arr[strlen(input_arr) - 2]) == 'k'){
			printf("%f C\n", convert_k_c(input_temp));
			printf("%f F\n", convert_k_f(input_temp));
		}
		else {
			printf("%f C\n", convert_c_k(input_temp));
			printf("%f F\n", convert_c_f(input_temp));
			printf("%f K\n", convert_c_k(input_temp));
		}
	}

	return 0;
}

