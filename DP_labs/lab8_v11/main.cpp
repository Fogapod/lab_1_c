#include <iostream>
#include <string>
#include <limits>
#include <tuple>

using std::string;
using std::cin;
using std::cout;
using std::endl;

string** init_matrix(string, int n, int m) {
    string **matrix = new string*[n];
        for(int i = 0; i < n; ++i)
            matrix[i] = new string[m];

    return matrix;
}

float** init_matrix(float, int n, int m) {
    float **matrix = new float*[n];
        for(int i = 0; i < n; ++i)
            matrix[i] = new float[m];

    return matrix;
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
        return std::make_tuple(result, false);
    }

    return std::make_tuple(result, true);
}

std::tuple<float, bool> get_user_input_float() {
    float result;
    cin >> result;

    if (cin.eof()) {
        exit(0);
    }

    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return std::make_tuple(result, false);
    }

    return std::make_tuple(result, true);
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
        return std::make_tuple(result, false);
    }

    return std::make_tuple(result, true);
}

void fill_matrix(string **matrix, int n, int m) {
	string value;
	bool ok;

    for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			while (true) {
				cout << "Enter value of matrix[" << i << "][" << j << "] (String)\n> ";
				std::tie(value, ok) = get_user_input_string();
				if (!ok)
					continue;

				matrix[i][j] = value;
				break;
			}
		}
	}
}

void fill_matrix(float **matrix, int n, int m) {
    float value;
	bool ok;

	for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            while (true) {
                cout << "Enter value of matrix[" << i << "][" << j << "] (Float)\n> ";
                std::tie(value, ok) = get_user_input_float();
                if (!ok)
                    continue;
	
				matrix[i][j] = value;
				break;
			}
		}
	}
}

void print_matrix(string **matrix, int n, int m) {
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

void print_matrix(float **matrix, int n, int m) {
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

void write_element(string **matrix, string item, int x, int y) {
	matrix[x][y] = item;
}

void write_element(float **matrix, float item, int x, int y) {
	matrix[x][y] = item;
}

void sort_rows(string **matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		std::sort(matrix[i], matrix[i] + m);
	}
}

void transpose_matrix(string **source, string **dest, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
            dest[j][i] = source[i][j];
        }
	}
}

void transpose_matrix(float **source, float **dest, int n, int m) {
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dest[j][i] = source[i][j];
        }
	}
}

void sort_rows(float **matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		std::sort(matrix[i], matrix[i] + m);
	}
}

int main() {
	int valType, rowCount, colCount;
    bool ok;

    while (true) {
        cout << "Please, choose matrix items type\n1: String\n2: Float\n";
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

    if (valType == 1) {
		string **matrix = init_matrix(string(), rowCount, colCount);
		fill_matrix(matrix, rowCount, colCount);
		print_matrix(matrix, rowCount, colCount);

		string **tempM = init_matrix(string(), colCount, rowCount);
		transpose_matrix(matrix, tempM, rowCount, colCount);
		sort_rows(tempM, colCount, rowCount);
        transpose_matrix(tempM, matrix, colCount, rowCount);

        cout << endl;
        print_matrix(matrix, rowCount, colCount);
    } else {
		float **matrix = init_matrix(float(), rowCount, colCount);
		fill_matrix(matrix, rowCount, colCount);
		print_matrix(matrix, rowCount, colCount);

		float **tempM = init_matrix(float(), colCount, rowCount);
        transpose_matrix(matrix, tempM, rowCount, colCount);
        sort_rows(tempM, colCount, rowCount);
        transpose_matrix(tempM, matrix, colCount, rowCount);

        cout << endl;
		print_matrix(matrix, rowCount, colCount);
	}

	return 0;
}
