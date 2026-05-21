#include "Intern.hpp"

// OCF
Intern::Intern(){}
Intern::Intern(const Intern& other){(void)other;}
Intern::~Intern(){}
Intern& Intern::operator=(const Intern& other){(void)other; return *this;}

AForm*  Intern::createSCF(std::string target){return new ShrubberyCreationForm(target);}
AForm*  Intern::createRRF(std::string target){ return new RobotomyRequestForm(target); }
AForm*  Intern::createPPF(std::string target){ return new PresidentialPardonForm(target);}

AForm*  Intern::makeForm(std::string name, std::string target)
{
    std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*helpers[3])(std::string) = {
        &Intern::createSCF,
        &Intern::createRRF,
        &Intern::createPPF
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == formTypes[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*helpers[i])(target);
        }
    }
    std::cout << "Error: Form name does not exist." << std::endl;
    return (NULL);
}

