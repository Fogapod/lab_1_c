#ifndef CAT_CPP
#define CAT_CPP

#include "animal.cpp"
#include <iostream>

class Cat: public Animal {
	public:
		Cat(): Animal() { }
		Cat(double age_in, std::string name_in): Animal(age_in, name_in) { }

		void speak() {
			std::cout << "meow" << std::endl;
		}

		void walk() {
			std::cout << "sneak" << std::endl;
		}
};

#endif
