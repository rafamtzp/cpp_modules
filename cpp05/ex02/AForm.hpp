#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm{
	private:
	const std::string name;
	bool              isSigned;
	const int         gradeToSign;
	const int         gradeToExecute;

	public:
	// Orthodox Canonical AForm
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	~AForm();

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
	bool	canBeExecuted(const Bureaucrat& b) const;
	virtual void	execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif


