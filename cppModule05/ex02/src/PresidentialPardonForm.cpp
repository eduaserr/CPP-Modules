#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& data)
	: AForm(data), _target(data._target) {
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& data) {
	std::cout << "PresidentialPardonForm copy assignment operator" << std::endl;
	if (this != &data) {
		AForm::operator=(data);
		_target = data._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor" << std::endl;
}

void PresidentialPardonForm::method() const {
	// TODO: Implementar mensaje de perdón por Zaphod Beeblebrox
}
