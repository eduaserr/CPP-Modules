#include "../inc/Form.hpp"

Form::Form():_name("Default"), _signed(false), _sigGrade(0), _execGrade(0){
	std::cout << "Form default constructor" << std::endl;
}
Form::Form(const Form& data):_name(data._name), _signed(false), _sigGrade(data._sigGrade), _execGrade(data._execGrade){
	std::cout << "Form copy constructor with class" << std::endl;
}
Form::Form(const std::string& name, int sigGrade, int execGrade): _name(name), _signed(false), _sigGrade(sigGrade), _execGrade(execGrade){
	std::cout << "Form copy constructor with parameters" << std::endl;
}
Form& Form::operator=(const Form& data)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &data)
		this->_signed = data._signed;
	return (*this);
}
std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName() << ", Form with grade to sign " << obj.getSignedGrade() <<
		" and grade to execute " << obj.getExecGrade() << " is";
	if (!obj.getSigned())
		os << " signed";
	else
		os << " not signed";
	return (os);
}
Form::~Form(){
	std::cout << "Form " << _name << " destructor" << std::endl;
}

void	Form::beSigned(Bureaucrat& a)
{
	if (_signed)
		throw IsSigned();
	if (_sigGrade < 1)
		throw GradeTooHighException();
	if (_sigGrade > 150)
		throw GradeTooLowException();
	if (a.getGrade() <= this->getSignedGrade()) {
		this->_signed = true;
		a.signForm(this->getName(), this->_signed);
		std::cout <<"The form "<< this->getName() <<" has been signed by "<< a.getName() << std::endl;
	}
	else {
		std::cout <<"The form "<< this->getName() <<" has not been signed by "<< a.getName() << std::endl;
		throw Form::GradeTooLowException();
	}
}

const std::string& Form::getName() const {
	return this->_name;
}
int Form::getSignedGrade() const {
	return this->_sigGrade;
}
int Form::getExecGrade() const {
	return this->_execGrade;
}
bool Form::getSigned() const {
	return this->_signed;
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