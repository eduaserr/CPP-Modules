#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& data);
    WrongCat& operator=(const WrongCat& data);
    ~WrongCat();

    void	makeSound() const;
};

#endif