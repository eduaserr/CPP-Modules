#include "../inc/AForm.hpp"

AForm::AForm():_name("Default"), _signed(false), _sigGrade(0), _execGrade(0){
	std::cout << "AForm default constructor" << std::endl;
}
AForm::AForm(const AForm& data):_name(data._name), _signed(false), _sigGrade(data._sigGrade), _execGrade(data._execGrade){
	std::cout << "AForm copy constructor with class" << std::endl;
}
AForm::AForm(const std::string& name, int sigGrade, int execGrade): _name(name), _signed(false), _sigGrade(sigGrade), _execGrade(execGrade){
	if (sigGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (sigGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "AForm copy constructor with parameters" << std::endl;
}
AForm& AForm::operator=(const AForm& data)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &data)
		this->_signed = data._signed;
	return (*this);
}
std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << obj.getName() << ", AForm with grade to sign " << obj.getSignedGrade() <<
		" and grade to execute " << obj.getExecGrade() << " is";
	if (obj.getSigned())
		os << " signed";
	else
		os << " not signed";
	return (os);
}
AForm::~AForm(){
	std::cout << "AForm " << _name << " destructor" << std::endl;
}

void	AForm::beSigned(Bureaucrat& a)
{
	if (_signed)
		throw IsSigned();
	if (a.getGrade() > this->getSignedGrade())
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

const std::string& AForm::getName() const {
	return this->_name;
}
int AForm::getSignedGrade() const {
	return this->_sigGrade;
}
int AForm::getExecGrade() const {
	return this->_execGrade;
}
bool AForm::getSigned() const {
	return this->_signed;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("AForm grade too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("AForm grade too low");
}

const char* AForm::IsSigned::what() const throw() {
	return ("AForm already signed");
}