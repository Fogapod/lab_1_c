#include <iostream>
#include "vector.cpp"

using std::cout;
using std::endl;

int main() {
	Vector v1;
	cout << "v1: (x: " << v1.get_x() << ", y: " << v1.get_y() << ")" << endl;
	Vector v2(10, -20);
	cout << "v2: (x: " << v2.get_x() << ", y: " << v2.get_y() << ")" << endl;
	Vector v3 = Vector(10, -20);
	cout << "v3: (x: " << v3.get_x() << ", y: " << v3.get_y() << ")" << endl;
	Vector v4(v1);
	cout << "v4: (x: " << v4.get_x() << ", y: " << v4.get_y() << ")" << endl;

	return 0;
}
