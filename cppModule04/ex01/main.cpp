#include "inc/Animal.hpp"
#include "inc/Brain.hpp"
#include "inc/Dog.hpp"
#include "inc/Cat.hpp"
#include "inc/WrongAnimal.hpp"
#include "inc/WrongCat.hpp"

static Cat*	catIdeas()
{
	Cat* cat(new Cat);
	for (int i = 0; i < 5; i++){
	std::string arr[] = {"EAT!", "PLAY!", "SLEEP!", "PEE!", "REPEAT!"};
	cat->getBrain()->setIdea(i, arr[i]);
	}
	return (cat);
}

static Dog*	dogIdeas()
{
	Dog* dog(new Dog);
	for (int i = 0; i < 5; i++){
	std::string arr[] = {"EAT!", "PLAY!", "SLEEP!", "PEE!", "REPEAT!"};
	dog->getBrain()->setIdea(i, arr[i]);
	}
	return (dog);
}
void checkIdeas(Animal* animals[], int size) {
	for (int i = 0; i < size; i++) {
		Brain* brain = animals[i]->getBrain();
		if (brain)
			std::cout << animals[i]->getType() << " " << i / 2 <<
			" is thinking about : " << brain->getIdea(i % 5) << std::endl;
	}
}

int main() {		
	const Animal* j = new Dog();
	const Animal* i = new Cat();

    delete j;
    delete i;

	std::cout << "\n	====== Constructor Build ======\n" << std::endl;

	Animal* animals[10];
	for (int i = 0; i < 10; i++){
		if (i % 2 == 0){
			std::cout << i << ". ";
			animals[i] = catIdeas();
		}
		else if (i % 2 != 0){
			std::cout << i << ". ";
			animals[i] = dogIdeas();
		}
	}
	std::cout << "\n	====== Checking Sounds ======\n" << std::endl;
	for (int i = 0; i < 10; i++){
		animals[i]->makeSound();
	}
	std::cout << "\n	====== Check Ideas ======\n" << std::endl;
	checkIdeas(animals, 10);

	std::cout << "\n	====== Stack memory ======\n" << std::endl;
	Dog Tob(*(Dog*)animals[1]);
	Tob.getBrain()->setIdea(0, "BARK!");
	std::cout << "\nOld idea was "<< animals[1]->getBrain()->getIdea(0);
	std::cout << ". New idea discover "<< Tob.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n	====== Heap memory ======\n" << std::endl;

	Dog *Pob(new Dog(*(Dog*)animals[1]));
	Pob->getBrain()->setIdea(0, "BARK!");
	std::cout << "\nOld idea was "<< animals[1]->getBrain()->getIdea(0);
	std::cout << ". New idea discover "<< Pob->getBrain()->getIdea(0) << std::endl;
	delete Pob;

	std::cout << "\n	====== Destructor Build ======\n" << std::endl;
	for (int i = 0; i < 10; i++){
		std::cout << i << ". ";
		delete animals[i];
	}

	return 0;
}
