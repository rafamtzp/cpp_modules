#include "Cure.hpp"

Cure::Cure(void)
{
	type = "Cure";
	std::cout <<"Cure created"<<std::endl;
}

Cure::~Cure(void)
{
	std::cout <<"Cure destroyed"<<std::endl;
}

Cure::Cure(const Cure& other)
{
	type = "Cure";
	std::cout << "Cure copy created" << std::endl;
}

void	Cure::use(ICharacter& target)
{
	std::cout
	<<"* heals"<<target.getName()<<"'s wounds *"
	<<std::endl;
}

AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

Cure&	Cure::operator=(const Cure& other)
{
	return (*this);
}