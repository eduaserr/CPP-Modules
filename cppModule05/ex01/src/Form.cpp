#include "../inc/Form.hpp"

Form::Form():_name("Default"), _signed(false), _sigGrade(0), _execGrade(0){
	std::cout << "Form default constructor" << std::endl;
}
Form::Form(const Form& data):_name(data._name), _signed(false), _sigGrade(data._sigGrade), _execGrade(data._execGrade){
	std::cout << "Form constructor with name" << std::endl;
}
Form::Form(const std::string& name, int sigGrade, int execGrade): _name(name), _signed(false), _sigGrade(sigGrade), _execGrade(execGrade){
	std::cout << "Form copy constructor" << std::endl;
}
Form& Form::operator=(const Form& data)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &data)
		data._name;
		data._signed;
		data._sigGrade;
		data._execGrade;
	return (*this);
}
std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName() << ", Form grade " << obj.getGrade() << ".";
	return (os);
}
Form::~Form(){
	std::cout << "Form default destructor" << std::endl;
}

void	Form::beSigned(Bureaucrat& a)
{
	if (!_signed)
		throw IsSigned();
	if (_sigGrade < 1)
		throw GradeTooHighException();
	if (_sigGrade > 150)
		throw GradeTooLowException();
	
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form grade too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form grade too low");
}

const char* Form::IsSigned::what() const throw() {
	return ("Form already signed");
}