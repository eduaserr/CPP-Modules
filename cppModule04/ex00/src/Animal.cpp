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

Dog::Dog() : Animal("Dog"){
	std::cout << _type << " default constructor" << std::endl;
}
Dog::Dog(const Dog& data) : Animal(data) {
	std::cout << _type << " copy constructor" << std::endl;
}
Dog& Dog::operator=(const Dog& data){
	std::cout << _type << " copy assignment operator called" << std::endl;
	if (this != &data)
		Animal::operator=(data);
	return (*this);
}
Dog::~Dog(){
	std::cout << _type << " destructor" << std::endl;
}
void	Dog::makeSound() const{
	std::cout << _type << ": guau!" << std::endl;
}

Cat::Cat() : Animal("Cat"){
	std::cout<< _type << " default constructor" << std::endl;
}
Cat::Cat(const Cat& data) : Animal(data){
	std::cout<< _type << " copy constructor" << std::endl;
}
Cat& Cat::operator=(const Cat& data){
	std::cout << _type << " copy assignment operator called" << std::endl;
	if (this != &data)
		Animal::operator=(data);
	return (*this);
}
Cat::~Cat(){
	std::cout << _type << " destructor" << std::endl;
}
void	Cat::makeSound() const{
	std::cout << _type << ": miau" << std::endl;
}