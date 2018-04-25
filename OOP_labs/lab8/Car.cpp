#include "Car.h"

Car::Car() {
	this->colour = 0;
	this->cost = 0.0;
}

Car::Car(int colour, float cost) {
	this->colour = colour;
    this->cost = cost;
}
