#ifndef CAR_H_
#define CAR_H_

#include <iostream>

class Car {
	public:
		int colour;  // colour index
		float cost;  // in US $

		void print() {
			std::cout << "Car colour index: " << colour << std::endl;
			std::cout << "Car cost: " << cost <<std::endl;
		}

		Car();
		Car(int colour, float cost);
};

#endif /* CAR_H_ */
