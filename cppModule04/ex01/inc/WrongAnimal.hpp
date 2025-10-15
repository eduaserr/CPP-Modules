#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string _type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& data);
    WrongAnimal(const std::string& type);
    WrongAnimal& operator=(const WrongAnimal& data);
    virtual ~WrongAnimal();

    void	setType(const std::string& type);
    std::string	getType() const;
    void	makeSound() const;
};

#endif