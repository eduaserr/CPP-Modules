#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
	Brain* _attribute;
public:
	Cat();
	Cat(const Cat& data);
	Cat& operator=(const Cat& data);
	~Cat();

	void	makeSound() const;
	Brain*	getBrain() const;
	void	setBrain(const Brain& brain);
};

#endif
