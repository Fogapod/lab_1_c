#include <iostream>

#include "cat.cpp"
#include "dog.cpp"
#include "animal.cpp"


int main() {
	Cat cat(1.0, "Tabby");
	Dog dog(4.5, "Jeff");

	std::cout << "Dog age: " << dog.get_age() << std::endl;
	std::cout << "Dog name: " << dog.get_name() << std::endl;
	std::cout << "Cat age: " << cat.get_age() << std::endl;
	std::cout << "Cat name: " << cat.get_name() << std::endl;

	cat.speak();
	dog.speak();

	cat.walk();
	dog.walk();

	return 0;
}
