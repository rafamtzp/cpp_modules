#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "Intern.hpp"

int main()
{
	Intern  intern;
	Bureaucrat boss("boss", 1);
	AForm *forms[5];

	forms[0] = intern.makeForm("robotomy request", "Bender");
	forms[1] = intern.makeForm("shrubbery creation", "home");
	forms[2] = intern.makeForm("presidential pardon", "pardon");
	forms[3] = intern.makeForm("Presidential pardon", "fake pardon");

	for (int i = 0; i < 3; i++)
	{
		if (forms[i])
		{
			boss.signForm(*forms[i]);
			boss.executeForm(*forms[i]);
			delete forms[i];
		}
	}
    return 0;
}