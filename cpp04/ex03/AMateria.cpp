#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout <<"A materia created"<<std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout <<type<< " created"<<std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	type = other.type;
	std::cout <<"AMateria copy created"<<std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destroyed"<<std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	return (*this);
}

std::string const &	AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout
	<<"A materia of some sort is being thrown at "
	<<target.getName()<<
	std::endl;
}