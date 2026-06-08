#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));

	Bureaucrat phil("phil", 50);

	PresidentialPardonForm ppf("ppf");
	RobotomyRequestForm rrf("rrf");
	ShrubberyCreationForm scf("shrub");

	std::cout << "---Phil has too low a grade---" << std::endl;
	phil.executeForm(ppf);
	phil.executeForm(rrf);
	phil.executeForm(scf);

	Bureaucrat bob("bob", 1);
	std::cout << std::endl;

	std::cout << "---Bob hasn't signed them---" << std::endl;
	bob.executeForm(ppf);
	bob.executeForm(rrf);
	bob.executeForm(scf);

	bob.signForm(ppf);
	bob.signForm(rrf);
	bob.signForm(scf);
	std::cout << std::endl;

	std::cout << "---Trying to execute the forms again after signing---" << std::endl;
	bob.executeForm(ppf);
	bob.executeForm(rrf);
	bob.executeForm(scf);
	std::cout << std::endl;

	std::cout << "--- Testing Robotomy 50% chance ---" << std::endl;
	for (int i = 0; i < 5; i++)
		bob.executeForm(rrf);
	std::cout << std::endl;

	std::cout << "--- The Middle-Man Test ---" << std::endl;
	// John can sign a Shrubbery form (req 145) but cannot execute it (req 137)
	Bureaucrat john("John", 140);
	ShrubberyCreationForm homeShrub("home");

	john.signForm(homeShrub);
	john.executeForm(homeShrub);

	// A middle-man for Presidential Pardon (req sign 25, exec 5)
	Bureaucrat vp("Vice President", 20);
	PresidentialPardonForm pardon("Some Guy");

	vp.signForm(pardon);
	vp.executeForm(pardon);

	return 0;
}