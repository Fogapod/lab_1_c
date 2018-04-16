#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include "Human.h"

class Student : public Human {
	public:
		bool on_lesson;

		Student() : Human::Human(), on_lesson(0) { };
		Student(std::string sn, std::string n, std::string mn, int a, int ol) : Human(sn, n, mn, a), on_lesson(ol) { };

		void print() {
			Human::print();
			std::cout << "Student on lesson: " << (on_lesson? "yes": "no") << std::endl;
		}
};

#endif /* HUMAN_H_ */
