#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string _target;

	virtual void method() const;

public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& data);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& data);
	~PresidentialPardonForm();
};

#endif
