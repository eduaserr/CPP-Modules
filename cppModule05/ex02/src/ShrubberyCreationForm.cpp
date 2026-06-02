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

void ShrubberyCreationForm::executeSuperClassForm(Bureaucrat const& executor) const {
	(void)executor;
	std::string name = _target + "_shruberry";
	std::ofstream file(name.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error opening file");
	file << TREE;
	file.close();
	std::cout << "Shrubbery planted in " << name << std::endl;
}
