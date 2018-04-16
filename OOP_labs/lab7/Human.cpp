#include "Human.h"

Human::Human() {
	this->surname = "empty";
    this->name    = "empty";
    this->midname = "empty";
    this->age     = 0;
}

Human::Human(std::string sn, std::string n, std::string mn, int a) {
    this->surname = sn;
    this->name    =  n;
    this->midname = mn;
 	this->age     =  a;
}
