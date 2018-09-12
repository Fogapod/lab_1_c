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
	bool ok;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			while (true) {
				cout << "Enter value of matrix[" << i << "][" << j << "] (" << (typeid(T) == typeid(int)? "Int": "String") << ")\n> ";
				std::tie(value, ok) = input_fn();
				if (!ok)
					continue;

				matrix[i][j] = value;
				break;
			}
		}
	}
}

template <class T>
T get_nth_item(T **matrix, int n, int size_x, int size_y) {
	for (int j = size_y; j > 0; j--) {
		for (int i = 0; i < size_x; i++) {
			if (n-- == 0)
				return matrix[i][j - 1];
		}
	}
	return T(); // error
}

template <class T>
void set_nth_item(T item, T **matrix, int n, int size_x, int size_y) {
	for (int j = size_y; j > 0; j--) {
		for (int i = 0; i < size_x; i++) {
            if (n-- == 0)
                matrix[i][j - 1] = item;
        }
    }
}

std::tuple<int, bool> get_user_input_int() {
	int result;
	cin >> result;

	if (cin.eof()) {
		exit(0);
    }

    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return std::make_tuple(-1, false);
	}

	return std::make_tuple(result, true);
}

std::tuple<string, bool> get_user_input_string() {
    string result;
    cin >> result;

	if (cin.eof()) {
        exit(0);
    }

    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return std::make_tuple("", false);
    }

    return std::make_tuple(result, true);
}

int main() {
	int valType, rowCount, colCount;
	bool ok;

	while (true) {
		cout << "Please, choose matrix items type\n1: Int\n2: String\n> ";
		std::tie(valType, ok) = get_user_input_int();
		if (!ok)
			continue;

		if (valType == 1 || valType == 2)
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

	int sortedEndIndex = 0;
	int maxN = rowCount * colCount;

	// code duplication, but nested templates do not work
	if (valType == 1) {
		int **m = init_matrix(int(), rowCount, colCount);
		fill_matrix(m, rowCount, colCount, get_user_input_int);
		print_matrix(m, rowCount, colCount);

		int valueToSort;
		while (true) {
			cout << "Please, enter value you want to place to the right upper corner\n> ";
			std::tie(valueToSort, ok) = get_user_input_int();
			if (ok)
				break;
		}
		for (int i = 0; i < maxN - 1; i++) {
			if (get_nth_item(m, i, rowCount, colCount) == valueToSort) {
				sortedEndIndex++;
				continue;
			}
			if (get_nth_item(m, i + 1, rowCount, colCount) != valueToSort)
                continue;

			// swap
			int temp;
			temp = get_nth_item(m, i + 1, rowCount, colCount);
			set_nth_item(get_nth_item(m, sortedEndIndex, rowCount, colCount), m, i + 1, rowCount, colCount);
			set_nth_item(temp, m, sortedEndIndex, rowCount, colCount);

			sortedEndIndex++;
		}
		print_matrix(m, rowCount, colCount);
	} else {
		string **m = init_matrix(string(), rowCount, colCount);
		fill_matrix(m, rowCount, colCount, get_user_input_string);
		print_matrix(m, rowCount, colCount);

		string valueToSort;
		while (true) {
			cout << "Please, enter value you want to place to the right upper corner\n> ";
			std::tie(valueToSort, ok) = get_user_input_string();
			if (ok)
				break;
        }
		for (int i = 0; i < maxN - 1; i++) {
			if (get_nth_item(m, i, rowCount, colCount) == valueToSort) {
                sortedEndIndex++;
				continue;
            }
            if (get_nth_item(m, i + 1, rowCount, colCount) != valueToSort)
				continue;
            // swap
            string temp;
            temp = get_nth_item(m, i + 1, rowCount, colCount);
            set_nth_item(get_nth_item(m, sortedEndIndex, rowCount, colCount), m, i + 1, rowCount, colCount);
            set_nth_item(temp, m, sortedEndIndex, rowCount, colCount);

            sortedEndIndex++;
        }
        print_matrix(m, rowCount, colCount);
	}

	return 0;
}
