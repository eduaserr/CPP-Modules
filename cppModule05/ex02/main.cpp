#include "inc/Bureaucrat.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "=== Bureaucrat Creation ===\n";
    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 50);
    Bureaucrat intern("Intern", 150);
    std::cout << boss << "\n" << mid << "\n" << intern << "\n\n";

    std::cout << "=== Forms Creation ===\n";
    ShrubberyCreationForm shrub("home");
    //RobotomyRequestForm robo("target");
    //PresidentialPardonForm pardon("prisoner");
    //std::cout << shrub << "\n" << robo << "\n" << pardon << "\n\n";

    std::cout << "=== Sign & Execute: Shrubbery ===\n";
    intern.signForm(shrub);		// fail: grade 150 > 145
    boss.signForm(shrub);		// success
    intern.executeForm(shrub);	// fail: not signed or low grade
    boss.executeForm(shrub);	// success: creates file
    std::cout << shrub << "\n\n";

    /*std::cout << "=== Sign & Execute: Robotomy ===\n";
    intern.signForm(robo);		// fail: grade 150 > 72
    mid.signForm(robo);			// success
    intern.executeForm(robo);	// fail: not signed or low grade
    mid.executeForm(robo);		// fail: grade 50 > 45
    boss.executeForm(robo);		// success: 50% chance
    std::cout << robo << "\n\n";

    std::cout << "=== Sign & Execute: Presidential ===\n";
    intern.signForm(pardon);	// fail: grade 150 > 25
    mid.signForm(pardon);		// success
    intern.executeForm(pardon);	// fail: not signed or low grade
    mid.executeForm(pardon);	// fail: grade 50 > 5
    boss.executeForm(pardon);	// success
    std::cout << pardon << "\n\n";*/

    std::cout << "=== Grade Limits ===\n";
    try { Bureaucrat bad("Bad", 0); } catch (const std::exception& e) { std::cout << "Error: " << e.what() << "\n"; }
    try { Bureaucrat bad("Bad", 151); } catch (const std::exception& e) { std::cout << "Error: " << e.what() << "\n"; }

    return 0;
}