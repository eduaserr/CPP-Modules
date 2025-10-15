#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
protected:
	std::string _ideas[100];
	std::string _type;
public:
	Brain();
	Brain(const Brain& data);
	Brain(const std::string& type);
	Brain& operator=(const Brain& data);
	virtual ~Brain();

	std::string	getType() const;
	void	setType(const std::string& type);
	virtual void	makeSound() const;
};

#endif
