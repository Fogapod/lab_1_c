#ifndef ANIMAL_CPP
#define ANIMAL_CPP

#include <string>
#include <iostream>

class NotImplemented: public std::logic_error
{
	public:
		NotImplemented() : std::logic_error("Not implemented.") {};
};

class Animal {
	double age;
	std::string name;
	
	protected:
		Animal(): age(0.0), name("[no name]") { }
		Animal(double age_in, std::string name_in): age(age_in), name(name_in) { }

	public:
		void speak() {
			throw NotImplemented();
		}

		void walk() {
			throw NotImplemented();
		}

		double get_age() {
			return age;
		}

		std::string get_name() {
			return name;
		}
};

#endif
