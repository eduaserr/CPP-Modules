#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150){
	std::cout << "Bureaucrat default constructor" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name){
	std::cout << "Bureaucrat constructor with name and grade" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& data): _name(data._name), _grade(data._grade){
	std::cout << "Bureaucrat copy constructor" << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& data)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &data)
		_grade = data._grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat default destructor" << std::endl;
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
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException& e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() 
				  << " because " << e.what() << std::endl;
	}
	catch (AForm::IsSigned& e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() 
				  << " because " << e.what() << std::endl;
	}
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
	return ("Bureaucrat grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat grade too low");
}