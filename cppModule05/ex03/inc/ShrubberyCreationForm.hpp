#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "AForm.hpp"

#define TREE "   / \\   \n" \
             "  /___\\  \n" \
             " /     \\ \n" \
             "/_______\\\n" \
             "   | |   \n"


class ShrubberyCreationForm : public AForm {
private:
	std::string _target;

	virtual void executeSuperClassForm(Bureaucrat const& executor) const;

public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& data);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& data);
	~ShrubberyCreationForm();
};

#endif
