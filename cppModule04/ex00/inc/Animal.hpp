#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

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
};

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog& data);
	Dog& operator=(const Dog& data);
	~Dog();

	void	makeSound() const;
};

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& data);
	Cat& operator=(const Cat& data);
	~Cat();

	void	makeSound() const;
};

// crear class wrongAnimal
// se puede separar por archivos Dog.cpp Cat.cpp...
#endif
