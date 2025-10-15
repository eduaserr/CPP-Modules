#include "../inc/Brain.hpp"

Brain::Brain() : _type("Brain"){
	std::cout << _type << " default constructor" << std::endl;
}
Brain::Brain(const Brain& data) : _type(data._type){
	std::cout << "Brain copy constructor" << std::endl;
}
Brain::Brain(const std::string& type) : _type(type){
	std::cout << "Brain constructor with type" << std::endl;
}
Brain& Brain::operator=(const Brain& data){
	std::cout << _type << " copy assignment operator called" << std::endl;
	if (this != &data)
		_type = data._type;
	return (*this);
}
Brain::~Brain(){
	std::cout << "Brain destructor" << std::endl;
}

void	Brain::setType(const std::string& type){
	_type = type;
}
std::string	Brain::getType() const{
	return (this->_type);
}
void	Brain::makeSound() const{
	std::cout << _type << ": sound" << std::endl;
}
