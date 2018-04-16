#include <iostream>
#include "Student.h"
#include "Boss.h"
#include "Human.h"

int main () {
	Boss b;
	std::cout << "[Empty boss]" << std::endl;
	b.print();
	std::cout << std::endl;

	b = Boss("Jack", "Adam", "Smith", 40, 5);
	std::cout << "[Boss]" << std::endl;
	b.print();
	std::cout << std::endl;

	Student s;
	std::cout << "[Empty student]" << std::endl;
    s.print();
	std::cout << std::endl;

	s = Student("Jimmy", "Wilson", "White", 18, 1);
	std::cout << "[Student]" << std::endl;
	s.print();

	return 0;
}
