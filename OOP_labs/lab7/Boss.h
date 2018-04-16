#ifndef BOSS_H_
#define BOSS_H_

#include <iostream>
#include "Human.h"

class Boss : public Human {
	public:
		int number_of_workers;

		Boss() : Human::Human(), number_of_workers(0) { };
		Boss(std::string sn, std::string n, std::string mn, int a, int nw) : Human(sn, n, mn, a), number_of_workers(nw) { };
		~Boss() {
			std::cout << "Boss destructor" << std::endl;
		}

		void print() {
			Human::print();
			std::cout << "Boss number of workers: " << number_of_workers << std::endl;
		}
};

#endif /* BOSS_H_ */
