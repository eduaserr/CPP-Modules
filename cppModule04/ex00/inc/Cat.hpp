#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& data);
	Cat& operator=(const Cat& data);
	~Cat();

	void	makeSound() const;
};

#endif
