#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
    std::cout << _type << " default constructor" << std::endl;
}
WrongCat::WrongCat(const WrongCat& data) : WrongAnimal(data){
    std::cout << _type << " copy constructor" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& data){
    std::cout << _type << " copy assignment operator called" << std::endl;
    if (this != &data)
        WrongAnimal::operator=(data);
    return (*this);
}
WrongCat::~WrongCat(){
    std::cout << _type << " destructor" << std::endl;
}
void	WrongCat::makeSound() const{
    std::cout << _type << ": wrong miau" << std::endl;
}