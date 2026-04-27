#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string _target;

	virtual void method() const;

public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& data);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& data);
	~RobotomyRequestForm();
};

#endif
