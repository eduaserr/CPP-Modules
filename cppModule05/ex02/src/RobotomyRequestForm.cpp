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

void RobotomyRequestForm::executeSuperClassForm(Bureaucrat const& executor) const {
	(void)executor;
	std::cout << "*(drilling noises...)*" << std::endl;
	int n = rand();
	if (n % 2 == 0)
		std::cout << _target << " has been robotomized successfully !" << std::endl;
	else
		std::cout << "robotomy of " << _target << " failed" << std::endl;
}
