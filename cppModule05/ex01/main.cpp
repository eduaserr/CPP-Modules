#include "inc/Bureaucrat.hpp"
#include "inc/Form.hpp"
#include <iostream>

static void	showError(const std::exception& e)
{
	std::cout << "Exception: " << e.what() << std::endl;
}

int	main()
{
	std::cout << "\n=== 1) Valid objects ===\n";
	Bureaucrat boss("Boss", 1);
	Bureaucrat intern("Intern", 150);
	Form easy("Easy", 150, 150);
	Form hard("Hard", 1, 1);

	std::cout << boss << std::endl;
	std::cout << intern << std::endl;
	std::cout << easy << std::endl;
	std::cout << hard << std::endl;

	std::cout << "\n=== 2) Copy / assignment ===\n";
	Bureaucrat copyBoss(boss);
	Bureaucrat assigned("Tmp", 42);
	assigned = intern;
	Form copyForm(easy);
	std::cout << copyBoss << std::endl;
	std::cout << assigned << std::endl;
	std::cout << copyForm << std::endl;

	std::cout << "\n=== 3) Grade limits ===\n";
	try { Bureaucrat bad1("Bad1", 0); } catch (const std::exception& e) { showError(e); }
	try { Bureaucrat bad2("Bad2", 151); } catch (const std::exception& e) { showError(e); }
	try { Form bad3("Bad3", 0, 10); } catch (const std::exception& e) { showError(e); }
	try { Form bad4("Bad4", 10, 151); } catch (const std::exception& e) { showError(e); }

	try { boss.incrementGrade(); } catch (const std::exception& e) { showError(e); }
	try { intern.decrementGrade(); } catch (const std::exception& e) { showError(e); }

	std::cout << "\n=== 4) beSigned() ===\n";
	try { hard.beSigned(intern); } catch (const std::exception& e) { showError(e); }
	hard.beSigned(boss);
	std::cout << hard << std::endl;

	std::cout << "\n=== 5) signForm() ===\n";
	Form formOk("FormOk", 150, 20);
	Form formKo("FormKo", 10, 20);

	boss.signForm(formOk);	 // should sign
	intern.signForm(formKo);   // should fail

	std::cout << formOk << std::endl;
	std::cout << formKo << std::endl;

	return 0;
}