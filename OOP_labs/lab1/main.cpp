#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include "Complex.h"

#define FILENAME "complex.txt"


using std::cout;
using std::endl;
using std::cin;

double get_double();
int get_int();
Complex get_complex();

void clear_stdin();

int main() {
	Complex n1 = create_complex(1, 10);
	Complex n2 = create_complex(-5, -7);
	double n3 = 7.5;

	while (true) {
		cout << "Select action by entering numner:" << endl;
		cout << "\t1.  show number" << endl;
		cout << "\t2.  enter number" << endl;
		cout << "\t3.  add 2 complex numbers" << endl;
		cout << "\t4.  substract complex numbers" << endl;
		cout << "\t5.  multiply complex number by double" << endl;
		cout << "\t6.  multiply 2 complex numbers" << endl;
		cout << "\t7.  divide complex number by double" << endl;
		cout << "\t8.  divide complex number by complex number" << endl;
		cout << "\t9.  get module of complex number" << endl;
		cout << "\t10. read complex numbers from file and find one with biggest module" << endl;

		switch (get_int()) {
		case 1:
			cout << "Select number you want to see:" << endl;
			cout << "\t1. 1st complex number" << endl;
			cout << "\t2. 2nd complex number" << endl;
			cout << "\t3. 3rd double  number" << endl;

			switch (get_int()) {
				case 1:
					cout << "First number: " << complex_to_string(n1) << endl;
					break;

				case 2:
					cout << "Second number: " << complex_to_string(n2) << endl;
					break;

				case 3:
					cout << "Third number: " << n3 << endl;
					break;

				default:
					cout << "Invalid input" << endl;
			}

			break;

		case 2:
			cout << "Select number you want to enter:" << endl;
			cout << "\t1. 1st complex number" << endl;
			cout << "\t2. 2nd complex number" << endl;
			cout << "\t3. 3rd double  number" << endl;

			switch (get_int()) {
			case 1:
				n1 = get_complex();
				break;

			case 2:
				n2 = get_complex();
				break;

			case 3:
				n3 = get_double();
				break;

			default:
				cout << "Invalid input" << endl;
			}

			break;

		case 3:
			cout << "Sum: " << complex_to_string(add_complex(n1, n2)) << endl;
			break;

		case 4:
			cout << "Substraction: " << complex_to_string(substract_complex(n1, n2)) << endl;
			break;

		case 5:
			cout << "Multiplication by number: " << complex_to_string(mult_complex_by_number(n1, n3)) << endl;
			break;

		case 6:
			cout << "Multiplication: " << complex_to_string(mult_complex(n1, n2)) << endl;
			break;

		case 7:
			cout << "Division by number: " << complex_to_string(divide_complex_by_number(n1, n3)) << endl;
			break;

		case 8:
			cout << "Division: " << complex_to_string(divide_complex(n1, n2)) << endl;
			break;

		case 9:
			cout << "Select number you want to use:" << endl;
			cout << "\t1. 1st" << endl;
			cout << "\t2. 2nd" << endl;

			switch (get_int()) {
				case 1:
					cout << "Module of first number: " << module_complex(n1) << endl;
					break;
				case 2:
					cout << "Module of second number: " << module_complex(n2) << endl;
					break;
				default:
					cout << "Invalid input" << endl;
			}
			break;

		case 10: {
			double real, imag;
			std::vector<Complex> complex_arr;

			Complex max, temp;
			std::fstream infile(FILENAME);

			if (infile >> real >> imag) {
				max = create_complex(real, imag);
				complex_arr.push_back(max);
			}
			else {
				cout << "Empty or invalid file" << endl;
				break;
			}

			int number_count = 1;
			for ( ; infile >> real >> imag; number_count++) {
				temp = create_complex(real, imag);
				complex_arr.push_back(temp);
			}

			for (int i = 0; i < number_count; i++) {
				if (module_complex(complex_arr.at(i)) > module_complex(max))
					max = complex_arr.at(i);
			}

			cout << "Complex with max module: " << complex_to_string(max) << endl;
			cout << "Numbers read: " << number_count << std::endl;
			break;

		}

		default:
			cout << "Invalid input" << endl;
		}
	}
	
	return 0;
}

int get_int() {
	int input;

	cout << ">";
	cin >> input;
	clear_stdin();

	return input;
}

double get_double() {
	double input;

	cout << ">";
	cin >> input;
	clear_stdin();

	return input;
}

Complex get_complex() {
	Complex input;

	cout << "Enter real part:" << endl;
	input.real = get_double();
	cout << "Enter imaginary part: " << endl;
	input.imag = get_double();

	return input;
}

void clear_stdin() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
