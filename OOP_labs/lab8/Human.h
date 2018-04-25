#ifndef HUMAN_H_
#define HUMAN_H_

#include <iostream>

class Human {
	public:
		std::string surname;
		std::string name;
		std::string midname;
		int age;

		virtual void print() {
			std::cout << "Human surname: " << surname << std::endl;
			std::cout << "Human name: "    << name    << std::endl;
			std::cout << "Human midname: " << midname << std::endl;
			std::cout << "Human age: "     << age     << std::endl;
		}

		Human();
		Human(std::string surname, std::string name, std::string midname, int age);
		virtual ~Human() = 0;
};

#endif /* HUMAN_H_ */
