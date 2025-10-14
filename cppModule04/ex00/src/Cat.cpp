#include "../inc/Cat.hpp"

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
