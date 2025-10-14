#include "../inc/Dog.hpp"

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
