#include "inc/Bureaucrat.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(0));

	std::cout << "=== Bureaucrat Creation ===\n";
	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Mid", 50);
	Bureaucrat intern("Intern", 150);
	std::cout << boss << "\n" << mid << "\n" << intern << "\n\n";

	std::cout << "=== Forms Creation ===\n";
	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robo("target");
	PresidentialPardonForm pardon("prisoner");
	std::cout << shrub << "\n" << robo << "\n" << pardon << "\n\n";

	std::cout << "=== Shrubbery ===\n";
	intern.signForm(shrub);		// fail: 150 > 145
	boss.signForm(shrub);		// success: 1 <= 145
	boss.signForm(shrub);		// fail: already signed
	intern.executeForm(shrub);	// fail: 150 > 137
	boss.executeForm(shrub);	// success: creates file

	std::cout << "\n=== Robotomy ===\n";
	intern.signForm(robo);		// fail: 150 > 72
	mid.signForm(robo);			// success: 50 <= 72
	boss.signForm(robo);		// fail: already signed
	intern.executeForm(robo);	// fail: 150 > 45
	mid.executeForm(robo);		// fail: 50 > 45
	boss.executeForm(robo);		// success: 50/50
	boss.executeForm(robo);		// success: 50/50 again

	std::cout << "\n=== Presidential ===\n";
	intern.signForm(pardon);	// fail: 150 > 25
	mid.signForm(pardon);		// fail: 50 > 25
	boss.signForm(pardon);		// success: 1 <= 25
	intern.executeForm(pardon);	// fail: 150 > 5
	mid.executeForm(pardon);	// fail: 50 > 5
	boss.executeForm(pardon);	// success

	return 0;
}