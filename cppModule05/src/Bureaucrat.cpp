#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}
Bureaucrat::Bureaucrat(const std::string& name, int grade){
	this->_name = name;
	this->_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& data){(void)data;}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& data)
{
	if (this != &data)
		_name = getName();
	return (*this);
}
Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}