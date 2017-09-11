#include <stdio.h>
#include <ctype.h>

int main(){
	char input_arr[100];
	int input_temp = 0;
	char input_scale = 'c';
	
	fgets(input_arr, 100, stdin);
	printf("%s", input_arr);
	printf("%d", input_arr);
	
	if (tolower(input_arr[-1]) == 'c'){
		int c;
	}
	input_temp = atoi(input_arr);


	return 0;
}

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
