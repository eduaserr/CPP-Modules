#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
protected:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain& data);
	Brain& operator=(const Brain& data);
	~Brain();

	std::string	getIdea(int i) const;
	void	setIdea(int i, const std::string& idea);
};

#endif
