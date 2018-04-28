#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <queue>
#include "Student.h"
#include "Complex.h"
#include "Car.h"

int main() {
	std::vector<Student> students;
	std::list<Complex> complex_nums;
	std::queue<Car> cars;

	std::srand(std::time(0));
	const std::string student_surnames[5] = {"Smith", "Jones", "Talor", "Williams", "Brown"};
	const std::string student_names[5]    = {"Liam", "William", "Mason", "Jmes", "Benjamin"};
	const std::string student_midnames[5] = {"James", "John", "William", "Thomas", "Edward"};

	for (int i = 0; i < 10; i++) {
		students.push_back(Student(
			student_surnames[std::rand() % 5],
			student_names[std::rand() % 5],
			student_midnames[std::rand() % 5],
			std::rand() % 6 + 17,  // age
			std::rand() % 2        // on lesson
		));

		complex_nums.push_back(create_complex(
			std::rand() % 201 - 100,
			std::rand() % 201 - 100
		));

		cars.push(Car(
			std::rand() % 101,                                  // colour index
			(float)(std::rand() % 10000000 + 10000000) / 100.0  // cost, $
		));
	}
	
	std::cout << "Students" << std::endl;
	for (std::vector<Student>::iterator it = students.begin(); it != students.end(); it++)
		it->print();

	std::cout << "Complex numbers:" << std::endl;
	for (Complex c : complex_nums)
		std::cout << complex_to_string(c) << std::endl;

	Car car = cars.front();
	car.print();

	return 0;
}
