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
	if (type == "ice")
	{
		std::cout
		<<"* shoots ice bolt at "<<target.getName()<<" *"
		<<std::endl;
		return ;
	}
	else if (type == "cure")
	{
		std::cout
		<<"* heals "<<target.getName()<<"'s wounds *"
		<<std::endl;
		return ;
	}
}
