#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal"){
    std::cout << _type << " default constructor" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& data) : _type(data._type){
    std::cout << "WrongAnimal copy constructor" << std::endl;
}
WrongAnimal::WrongAnimal(const std::string& type) : _type(type){
    std::cout << "WrongAnimal constructor with type" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& data){
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &data)
        _type = data._type;
    return (*this);
}
WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor" << std::endl;
}

void	WrongAnimal::setType(const std::string& type){
    _type = type;
}
std::string	WrongAnimal::getType() const{
    return (this->_type);
}
void	WrongAnimal::makeSound() const{
    std::cout << _type << ": wrong sound" << std::endl;
}