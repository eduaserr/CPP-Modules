#include "../inc/Cat.hpp"

Cat::Cat() : Animal("Cat"), _attribute(new Brain){
	std::cout << _type << " default constructor" << std::endl;
}
Cat::Cat(const Cat& data) : Animal(data), _attribute(new Brain(*data._attribute)){
	std::cout << _type << " copy constructor" << std::endl;
}
Cat& Cat::operator=(const Cat& data){
	std::cout << _type << " copy assignment operator called" << std::endl;
	if (this != &data){
		Animal::operator=(data);
		if (_attribute)
			delete _attribute;
		this->_attribute = new Brain(*data._attribute);
	}
	return (*this);
}
Cat::~Cat(){
	std::cout << _type << " destructor" << std::endl;
	if (_attribute)
		delete _attribute;
}
void	Cat::makeSound() const{
	std::cout << _type << ": miau" << std::endl;
}

Brain*	Cat::getBrain() const{
	return this->_attribute;
}

void	Cat::setBrain(const Brain& brain){
	if (_attribute)
		delete _attribute;
	this->_attribute = new Brain(brain);
}
