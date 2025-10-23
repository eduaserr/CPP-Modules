#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {
protected:
	std::string _type;
public:
	Animal();
	Animal(const Animal& data);
	Animal(const std::string& type);
	Animal& operator=(const Animal& data);
	virtual ~Animal();

	std::string	getType() const;
	void	setType(const std::string& type);
	virtual void	makeSound() const;
	virtual Brain*	getBrain() const;
};

#endif
