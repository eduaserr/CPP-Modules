#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150){
	std::cout << _name << " default constructor" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade){
	std::cout << _name << " constructor with name and grade" << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat& data): _name(data._name), _grade(data._grade){
	std::cout << _name << " copy constructor" << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& data)
{
	std::cout << _name << " copy assignment operator called" << std::endl;
	if (this != &data)
		_grade = data._grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}

Bureaucrat::~Bureaucrat(){
	std::cout << _name << " default desconstructor" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}
void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low";
}