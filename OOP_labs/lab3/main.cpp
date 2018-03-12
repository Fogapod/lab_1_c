#include <iostream>
#include "vector.h"

using std::cout;
using std::endl;

int main() {
	Vector v1, v2;

	v1.x = 2;
	v1.y = 5;

	v2.x = -2;
	v2.y = 1.5;

	cout << "v1 module: " << v1.get_module() << endl;
	v1.add(v2);
	cout << "v1 += v2: (x: " <<v1.x << " y: " << v1.y << ")" << endl;
	v2.substract(v1);
	cout << "v2 -= v1: (x: " <<v2.x << " y: " << v2.y << ")" << endl;


	return 0;
}
