#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& data)
	: AForm(data), _target(data._target) {
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& data) {
	std::cout << "RobotomyRequestForm copy assignment operator" << std::endl;
	if (this != &data) {
		AForm::operator=(data);
		_target = data._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

void RobotomyRequestForm::method() const {
	// TODO: Implementar sonidos de drilling y 50% de éxito/fallo
}
