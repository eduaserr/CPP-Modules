#include "inc/Animal.hpp"
#include "inc/Brain.hpp"
#include "inc/Dog.hpp"
#include "inc/Cat.hpp"

int main() {
	//Animal	animal("test");
	const Animal* j = new Dog();

	delete j;
	return 0;
}
