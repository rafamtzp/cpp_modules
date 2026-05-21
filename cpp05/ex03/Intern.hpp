#pragma once

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern 
{
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm   *makeForm(std::string name, std::string target);

    // helpers
    AForm   *createSCF(std::string target);
    AForm   *createRRF(std::string target);
    AForm   *createPPF(std::string target);
};
