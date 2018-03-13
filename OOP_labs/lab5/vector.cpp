#include <cmath>

class Vector {
	double x, y;

	public:
		Vector() {
			x = 0.0;
			y = 0.0;
		}

		Vector(double i_x, double i_y): x(i_x * 10), y(i_y * 10) { }

		Vector(const Vector &obj) {
			x = obj.x;
			y = obj.y;
		}

		double get_x() {
			return x;
		}

		double get_y() {
			return y;
		}

		double get_module() {
			return std::hypot(x, y);
		}

		friend bool operator==(const Vector &left, const Vector &right) {
			return left.x == right.x && left.y == right.y;
		}

		friend bool operator!=(const Vector &left, const Vector &right) {
            return !(left == right);
        }

		Vector &operator=(const Vector &right) {
			if (this != &right) {
				x = right.x;
				y = right.y;
			}
			return *this;
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
