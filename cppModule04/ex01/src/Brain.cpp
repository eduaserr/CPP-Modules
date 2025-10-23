#include "../inc/Brain.hpp"

Brain::Brain(){
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";
	std::cout << "Brain default constructor" << std::endl;
}
Brain::Brain(const Brain& data){
	for (int i = 0; i < 100; i++)
			_ideas[i] = data._ideas[i];
	std::cout << "Brain copy constructor" << std::endl;
}
Brain& Brain::operator=(const Brain& data){
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &data)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = data._ideas[i];
	}
	return (*this);
}
Brain::~Brain(){
	std::cout << "Brain destructor" << std::endl;
}

void	Brain::setIdea(int i, const std::string& idea){
	_ideas[i] = idea;
}
std::string	Brain::getIdea(int i) const{
	if (i >= 0 && i < 100)
		return (this->_ideas[i]);
	return "";
}

