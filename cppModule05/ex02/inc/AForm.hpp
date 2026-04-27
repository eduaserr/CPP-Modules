#ifndef AFORM_HPP
#define AFORM_HPP

class Bureaucrat;

#include "Bureaucrat.hpp"

class AForm {
private:
	const std::string	_name;
	bool				_signed;
	const int			_sigGrade;
	const int			_execGrade;

public:
	AForm();
	AForm(const std::string& name, int sigGrade, int execGrade);
	AForm(const AForm& data);
	AForm& operator=(const AForm& data);
	~AForm();

	virtual void	method() const = 0;
	void			beSigned(Bureaucrat& a);
	void			execute(Bureaucrat const&) const;

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

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif