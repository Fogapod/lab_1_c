#ifndef DOG_CPP
#define DOG_CPP

#include "animal.cpp"
#include <iostream>

class Dog: public Animal {
	public:
		Dog(): Animal() { }
		Dog(double age_in, std::string name_in): Animal(age_in, name_in) { }

		void speak() {
			std::cout << "bark" << std::endl;
		}

		void walk() {
			std::cout << "walk" << std::endl;
		}
};

#endif
