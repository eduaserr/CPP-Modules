#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
private:
	const std::string	_name;
	int	_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& data);
	Bureaucrat& operator=(const Bureaucrat& data);
	~Bureaucrat();

	std::string	getName() const;
	std::string	getGrade() const;
	void		setName(const std::string& name);
	void		setGrade(const std::string& name);
	void		incrementGrade(const int grade);
	void		decrementGrade(const int grade);
	void	GradeTooHighException();
	void	GradeTooLowException();
};

#endif
