#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
private:
	const std::string	_name;
	bool				_signed;
	const int			_sigGrade;
	const int			_execGrade;

public:
	Form();
	Form(const std::string& name, int grade);
	Form(const Form& data);
	Form& operator=(const Form& data);
	~Form();

	void	beSigned(Bureaucrat& a);
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif