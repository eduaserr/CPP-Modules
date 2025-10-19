#include "inc/Animal.hpp"
#include "inc/Brain.hpp"
#include "inc/Dog.hpp"
#include "inc/Cat.hpp"
#include "inc/WrongAnimal.hpp"
#include "inc/WrongCat.hpp"

int main() {
	Animal* def = new Animal();
	Animal* toby = new Dog();
	Animal* sasha = new Cat();

	std::cout << std::endl;
	std::cout << sasha->getType() << std::endl;
	std::cout << toby->getType() << std::endl;
	sasha->makeSound(); //will output the cat sound!
	toby->makeSound();
	def->makeSound();
	std::cout << std::endl;

	delete sasha;
	delete toby;
	delete def;

	std::cout << std::endl;
	WrongAnimal* Human = new WrongAnimal();
	WrongAnimal* noCat = new WrongCat();
	std::cout << std::endl;
	Human->makeSound();
	noCat->makeSound();
	std::cout << std::endl;
	
	delete noCat;
	delete Human;
	return 0;
}
