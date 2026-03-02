#include "Cure.hpp"

Cure::Cure(void)
{
	type = "cure";
	std::cout <<"Cure created"<<std::endl;
}

Cure::~Cure(void)
{
	std::cout <<"Cure destroyed"<<std::endl;
}

Cure::Cure(const Cure& other)
{
	type = "cure";
	std::cout << "Cure copy created" << std::endl;
}

void	Cure::use(ICharacter& target)
{
	AMateria::use(target);
}

AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

Cure&	Cure::operator=(const Cure& other)
{
	return (*this);
}