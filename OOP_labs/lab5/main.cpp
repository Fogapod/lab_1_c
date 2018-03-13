#include <iostream>
#include "vector.cpp"

using std::cout;
using std::endl;

int main() {
	Vector v1(10, -20);
	Vector v2(-10, 20);
	Vector v3 = v2;

	cout << "v1 == v2: " << (v1 == v2) << endl;
	cout << "v1 != v2: " << (v1 != v2) << endl;

	cout << "v3 == v2: " << (v3 == v2) << endl;
    cout << "v3 != v2: " << (v3 != v2) << endl;

	return 0;
}
