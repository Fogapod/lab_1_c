#include <cmath>

class Vector {
public:
	double x, y;

	double get_module() {
		return std::hypot(x, y);
	}

	void add(Vector v2) {
		x += v2.x;
		y += v2.y;
	}

	void substract(Vector v2) {
		x -= v2.x;
		y -= v2.y;
	}
};
