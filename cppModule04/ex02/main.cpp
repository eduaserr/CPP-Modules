#include "inc/Animal.hpp"
#include "inc/Brain.hpp"
#include "inc/Dog.hpp"
#include "inc/Cat.hpp"

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
	//Animal	animal("test");
	const Animal* j = new Dog();

	delete j;
	return 0;
}
