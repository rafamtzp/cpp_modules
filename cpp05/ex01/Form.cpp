#include "Form.hpp"
#include "Bureaucrat.hpp"

// Orthodox canonical form
Form::Form():
name(""), isSigned(false), 
gradeToSign(1), gradeToExecute(1){}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute):
name(name), isSigned(false), 
gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other):
name(other.name), isSigned(other.isSigned), 
gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){}

// exception classes
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Error. This grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error. This grade is too low!");
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return (*this);
}

Form::~Form(){};

// Getters
const std::string& Form::getName() const {return (name);}

bool               Form::getIsSigned() const {return (isSigned);}

int                Form::getGradeToSign() const {return (gradeToSign);}

int                Form::getGradeToExecute() const {return (gradeToExecute);}

std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	os << "Form: " << obj.getName()
	<< ", isSigned: " << std::boolalpha << obj.getIsSigned()
	<< ", gradeToSign: " << obj.getGradeToSign()
	<< ", gradeToExecute: " << obj.getGradeToExecute();
	return (os);
}

void	Form::beSigned(Bureaucrat&	b)
{
	if (b.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw Form::GradeTooLowException();
}
