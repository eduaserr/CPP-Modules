#include "../inc/Animal.hpp"

Animal::Animal() : _type("Animal"){
	std::cout << _type << " default constructor" << std::endl;
}
Animal::Animal(const Animal& data) : _type(data._type){
	std::cout << "Animal copy constructor" << std::endl;
}
Animal::Animal(const std::string& type) : _type(type){
	std::cout << "Animal constructor with type" << std::endl;
}
Animal& Animal::operator=(const Animal& data){
	std::cout << _type << " copy assignment operator called" << std::endl;
	if (this != &data)
		_type = data._type;
	return (*this);
}
Animal::~Animal(){
	std::cout << "Animal destructor" << std::endl;
}

void	Animal::setType(const std::string& type){
	_type = type;
}
std::string	Animal::getType() const{
	return (this->_type);
}
void	Animal::makeSound() const{
	std::cout << _type << ": sound" << std::endl;
}
Brain*	Animal::getBrain() const{
	return NULL;
}