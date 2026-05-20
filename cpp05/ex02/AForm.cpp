#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Orthodox canonical form
AForm::AForm():
name(""), isSigned(false), 
gradeToSign(1), gradeToExecute(1){}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute):
name(name), isSigned(false), 
gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other):
name(other.name), isSigned(other.isSigned), 
gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){}

// exception classes
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Error. This grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Error. This grade is too low!");
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return (*this);
}

AForm::~AForm(){};

// Getters
const std::string& AForm::getName() const {return (name);}

bool               AForm::getIsSigned() const {return (isSigned);}

int                AForm::getGradeToSign() const {return (gradeToSign);}

int                AForm::getGradeToExecute() const {return (gradeToExecute);}

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	os << "AForm: " << obj.getName()
	<< ", isSigned: " << std::boolalpha << obj.getIsSigned()
	<< ", gradeToSign: " << obj.getGradeToSign()
	<< ", gradeToExecute: " << obj.getGradeToExecute();
	return (os);
}

void	AForm::beSigned(Bureaucrat&	b)
{
	if (b.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

bool	AForm::canBeExecuted(const Bureaucrat& b) const
{
	if (b.getGrade() <= gradeToExecute && isSigned == true)
		return (true);
	return (false);
}
