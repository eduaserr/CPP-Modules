#include "../inc/Intern.hpp"

Intern::Intern() {
	std::cout << "Intern: default constructor called" << std::endl;
}

Intern::Intern(const Intern &data) {
	std::cout << "Intern: copy constructor called" << std::endl;
	*this = data;
}

Intern &Intern::operator=(const Intern &data) {
	std::cout << "Intern: assignation operator called" << std::endl;
	if (this == &data)
		return *this;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern: destructor called" << std::endl;
}

static AForm *createPresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

static AForm *createRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

static AForm *createShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	const std::string names[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	AForm *(*creators[3])(const std::string &) = {
		&createPresidentialPardonForm,
		&createRobotomyRequestForm,
		&createShrubberyCreationForm
	};

	for (int i = 0; i < 3; i++) {
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}
	std::cout << "Intern cannot create form: " << formName << std::endl;
	return NULL;
}
