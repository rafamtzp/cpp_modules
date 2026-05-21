#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

// Orthodox canonical form
RobotomyRequestForm::RobotomyRequestForm():
AForm("Robotomy Request", 72, 45), target(""){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
AForm("Robotomy Request", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()),
target(other.target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw FormNotSignedException();

	std::cout << "* Brrrrrrrrrrrrrrrr *" << std::endl;

	if (rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << target << ": robotomy failed..." << std::endl;

	return ;
}
