#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog& data);
	Dog& operator=(const Dog& data);
	~Dog();

	void	makeSound() const;
};

#endif