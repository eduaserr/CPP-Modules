#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;

#include "Bureaucrat.hpp"

class Form {
private:
	const std::string	_name;
	bool				_signed;
	const int			_sigGrade;
	const int			_execGrade;

public:
	Form();
	Form(const std::string& name, int sigGrade, int execGrade);
	Form(const Form& data);
	Form& operator=(const Form& data);
	~Form();

	void	beSigned(Bureaucrat& a);

	const	std::string& getName() const;
	int		getSignedGrade() const;
	int		getExecGrade() const;
	bool	getSigned() const;

	class IsSigned : public std::exception {
	public:
		virtual const char *what() const throw();
	};

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