#include "inc/Bureaucrat.hpp"
#include "inc/Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
	std::srand(std::time(0));

	Intern intern;
	Bureaucrat boss("Boss", 1);

	AForm* f;

	// robotomy
	f = intern.makeForm("robotomy request", "Bender");
	if (f) { boss.signForm(*f); boss.executeForm(*f); delete f; }

	// ahruberry
	f = intern.makeForm("shrubbery creation", "home");
	if (f) { boss.signForm(*f); boss.executeForm(*f); delete f; }

	// presidential
	f = intern.makeForm("presidential pardon", "Arthur Dent");
	if (f) { boss.signForm(*f); boss.executeForm(*f); delete f; }

	// invalid name
	f = intern.makeForm("coffee request", "office");
	if (!f) std::cout << "Invalid form test OK\n";
	else delete f;

	return 0;
}