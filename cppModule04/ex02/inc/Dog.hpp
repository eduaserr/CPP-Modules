#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal {
private:
	Brain* _attribute;
public:
	Dog();
	Dog(const Dog& data);
	Dog& operator=(const Dog& data);
	~Dog();

	void	makeSound() const;
	Brain*	getBrain() const;
	void	setBrain(const Brain& brain);
};

#endif