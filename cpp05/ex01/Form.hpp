#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
	const std::string name;
	bool              isSigned;
	const int         gradeToSign;
	const int         gradeToExecute;

	public:
	// Orthodox Canonical Form
	Form();
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	// Getters
	const std::string& getName() const;
	bool               getIsSigned() const;
	int                getGradeToSign() const;
	int                getGradeToExecute() const;

	// Exception Classes
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	// More methods
	void	beSigned(Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif


