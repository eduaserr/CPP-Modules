#include "../inc/Dog.hpp"

Dog::Dog() : Animal("Dog"){
	this->_attribute = new Brain;
	std::cout << _type << " default constructor" << std::endl;
}
Dog::Dog(const Dog& data) : Animal(data), _attribute(new Brain(*data._attribute)) {
	std::cout << _type << " copy constructor" << std::endl;
}
Dog& Dog::operator=(const Dog& data){
	std::cout << _type << " copy assignment operator called" << std::endl;
	if (this != &data){
		Animal::operator=(data);
		delete _attribute;
		this->_attribute = new Brain(*data._attribute);
	}
	return (*this);
}
Dog::~Dog(){
	std::cout << _type << " destructor" << std::endl;
	delete _attribute;
}
void	Dog::makeSound() const{
	std::cout << _type << ": guau!" << std::endl;
}

Brain*	Dog::getBrain() const {
	return this->_attribute;
}

void	Dog::setBrain(const Brain& brain){
	delete _attribute;
	this->_attribute = new Brain(brain);
}
