#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string _target;

	virtual void method() const;

public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& data);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& data);
	~ShrubberyCreationForm();
};

#endif
