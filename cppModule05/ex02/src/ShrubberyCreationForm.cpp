#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& data)
	: AForm(data), _target(data._target) {
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& data) {
	std::cout << "ShrubberyCreationForm copy assignment operator" << std::endl;
	if (this != &data) {
		AForm::operator=(data);
		_target = data._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

void ShrubberyCreationForm::method() const {
	// TODO: Implementar creación de archivo con ASCII trees
}
