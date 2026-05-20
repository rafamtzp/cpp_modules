#include "RobotomyRequestForm.hpp"
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
	if (AForm::canBeExecuted(executor))
	{
		std::cout << "* Brrrrrrrrrrrrrrrr *" << std::endl;

		if (rand() % 2 == 0)
			std::cout << target << " has been robotomized successfully!" << std::endl;
		else
			std::cout << target << ": robotomy failed..." << std::endl;

		return ;
	}
	throw AForm::GradeTooLowException();
}
