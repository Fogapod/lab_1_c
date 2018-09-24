#include <algorithm>
#include <iostream>
#include <tuple>
#include <typeinfo>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class T>
T** init_matrix(T, int n, int m) {
	T **matrix = new T*[n];
		for(int i = 0; i < n; ++i)
			matrix[i] = new T[m];

	return matrix;
}

template <class T>
void print_matrix(T **matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		cout << "[";
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j];
			if (j != m - 1)
				cout << " ";
		}
		cout << "]\n";
	}
}

template <class T>
void fill_matrix(T **matrix, int n, int m, std::tuple<T, bool>(*input_fn)()) {
	T value;
	string typeName;

	if (typeid(T) == typeid(int)) {
		typeName = "Int";
	} else if (typeid(T) == typeid(float)) {
		typeName = "Float";
	} else {
		typeName = "Char";
	}

	bool ok;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			do {
				cout << "Enter value of matrix[" << i << "][" << j << "] (" << typeName << ")\n> ";
				std::tie(value, ok) = input_fn();
			} while(!ok);

			matrix[i][j] = value;
		}
	}
}

template <class T>
void transpose_matrix(T **source, T **dest, int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dest[j][i] = source[i][j];
}

std::tuple<int, bool> get_user_input_int() {
	int result;
	cin >> result;

	if (cin.eof())
		exit(0);

	if (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return std::make_tuple(result, false);
	}

	return std::make_tuple(result, true);
}

std::tuple<float, bool> get_user_input_float() {
	float result;
	cin >> result;
	if (cin.eof())
		exit(0);

	if (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return std::make_tuple(result, false);
	}

	return std::make_tuple(result, true);
}

template <class T>
void sort_rows(T **matrix, int n, int m) {
	for (int i = 0; i < n; i++)
		std::sort(matrix[i], matrix[i] + m);
}

std::tuple<char, bool> get_user_input_char() {
	char result;
	cin >> result;

	if (cin.eof())
		exit(0);

	if (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return std::make_tuple(result, false);
	}

	return std::make_tuple(result, true);
}

int main() {
	int valType, rowCount, colCount;
	bool ok;

	while (true) {
		cout << "Please, choose matrix items type\n1: Int\n2: Char\n3: Float\n";
		std::tie(valType, ok) = get_user_input_int();
		if (!ok)
			continue;

		if (valType == 1 || valType == 2 || valType == 3)
			break;
	}
	while (true) {
		cout << "Please, enter number of colums (<=50)\n> ";
		std::tie(colCount, ok) = get_user_input_int();
		if (!ok)
			continue;

		if (colCount > 0 && colCount <= 50)
			break;
	}
	while (true) {
		cout << "Please, enter number of rows (<=100)\n> ";
		std::tie(rowCount, ok) = get_user_input_int();
		if (!ok)
			continue;

		if (rowCount > 0 && rowCount <= 100)
			break;
	}

	// code duplication, but nested templates do not work
	if (valType == 1) {
		int **m = init_matrix(int(), rowCount, colCount);
		fill_matrix(m, rowCount, colCount, get_user_input_int);
		print_matrix(m, rowCount, colCount);

		int **tempM = init_matrix(int(), colCount, rowCount);
		transpose_matrix(m, tempM, rowCount, colCount);
		sort_rows(tempM, colCount, rowCount);
		transpose_matrix(tempM, m, colCount, rowCount);

		cout << endl;
		print_matrix(m, rowCount, colCount);

	} else if (valType == 2) {
		char **m = init_matrix(char(), rowCount, colCount);
		fill_matrix(m, rowCount, colCount, get_user_input_char);
		print_matrix(m, rowCount, colCount);

		char **tempM = init_matrix(char(), colCount, rowCount);
		transpose_matrix(m, tempM, rowCount, colCount);
		sort_rows(tempM, colCount, rowCount);
		transpose_matrix(tempM, m, colCount, rowCount);

		cout << endl;
		print_matrix(m, rowCount, colCount);
	} else {
		float **m = init_matrix(float(), rowCount, colCount);
		fill_matrix(m, rowCount, colCount, get_user_input_float);
		print_matrix(m, rowCount, colCount);

		float **tempM = init_matrix(float(), colCount, rowCount);
		transpose_matrix(m, tempM, rowCount, colCount);
		sort_rows(tempM, colCount, rowCount);
		transpose_matrix(tempM, m, colCount, rowCount);

		cout << endl;
		print_matrix(m, rowCount, colCount);
	}

	return 0;
}
