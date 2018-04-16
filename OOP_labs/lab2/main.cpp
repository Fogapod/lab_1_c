#include <iostream>
#include <ctime>

#define ARR_SIZE 5

using std::cout;
using std::endl;


void print_array(int arr[], int arr_size);
int check_condition(int arr[], int arr_size);
void reverse_array(int arr[], int arr_size);
void make_not_decreasing(int arr[], int arr_size);
void make_not_increasing(int arr[], int arr_size);

void (*handler(int arr[], int arr_size))(int arr[], int arr_size);


int main() {
	std::srand(std::time(0));

	int arr[ARR_SIZE];
	void (*f_ptr)(int arr[], int arr_size);  /* placeholder for function */

	for (int i = 0; i < ARR_SIZE; i++)
		arr[i] = std::rand() % 201 - 100;  /* -100 ~ 100 */

	cout << "New array:" << endl;
	print_array(arr, ARR_SIZE);

	f_ptr = handler(arr, ARR_SIZE);
	f_ptr(arr, ARR_SIZE);

	cout << "Final array:" << endl;
	print_array(arr, ARR_SIZE);

	return 0;
}

void print_array(int arr[], int arr_size) {
	cout << "[";

	for (int i = 0; i < arr_size; i++) {
		cout << arr[i];
		if (i == arr_size - 1)
			break;
		cout << ", ";
	}

	cout << "]" << endl;
}

int check_condition(int arr[], int arr_size) {
	/*
	 * returns:
	 *    0: 1st element == sum of all elements
	 *   -1: 1st element <  sum of all elements
	 *    1: 1st element >  sum of all elements
	 */

	int sum = 0;

	for (int i = 0; i < arr_size; i++)
		sum += arr[i];
	
	return (sum == arr[0])? 0: (sum < arr[0])? -1: 1;

}

void reverse_array(int arr[], int arr_size) {
	int temp;

	for (int i = 0; i < arr_size / 2; i++) {
		temp = arr[i];
		arr[i] = arr[arr_size - 1 - i];
		arr[arr_size - 1 - i] = temp;
	}
}

void make_not_decreasing(int arr[], int arr_size) {
	int temp;

	for (int i = 0; i < arr_size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			break;
		}
	}
}

void make_not_increasing(int arr[], int arr_size) {
	int temp;

	for (int i = 0; i < arr_size - 1; i++) {
		if (arr[i] < arr[i + 1]) {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            break;
        }
	}
}

void (*handler(int arr[], int arr_size))(int arr[], int arr_size) {
	switch (check_condition(arr, arr_size)) {
		case  0:
			cout << "First element is equal to sum of elements, reversing array" << endl;
			return reverse_array;
		case  1:
			cout << "First element is smaller than sum of elements, making array elements not decreasing" << endl;
			return make_not_decreasing;
		case -1:
			cout << "First element is bigger than sum of elements, making array elements not increasing" << endl;
			return make_not_increasing;
		default:
			cout << "Error: bad condition recieved, reversing array" << endl;
			return reverse_array;
	}
}
