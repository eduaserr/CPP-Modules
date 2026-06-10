#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

class AForm;

class Intern {

	public:

	Intern();
	Intern(const Intern &data);
	~Intern();

	Intern &operator=(const Intern &data);

	AForm *makeForm(const std::string &FormName, const std::string &target);
};

#endif