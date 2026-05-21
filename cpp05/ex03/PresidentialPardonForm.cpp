#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Orthodox canonical form
PresidentialPardonForm::PresidentialPardonForm():
AForm("Presidential Pardon", 25, 5), target(""){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
AForm("Presidential Pardon", 25, 5), target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()),
target(other.target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw FormNotSignedException();

	std::cout << target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
	return ;
}
