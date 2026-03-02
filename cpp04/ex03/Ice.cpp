#include "Ice.hpp"

Ice::Ice(void)
{
	type = "ice";
	std::cout <<"Ice created"<<std::endl;
}

Ice::~Ice(void)
{
	std::cout <<"Ice destroyed"<<std::endl;
}

Ice::Ice(const Ice& other)
{
	type = "ice";
	std::cout << "Ice copy created" << std::endl;
}

void	Ice::use(ICharacter& target)
{
	AMateria::use(target);
}

AMateria	*Ice::clone() const
{
	if (!this)
		return (NULL);
	return (new Ice(*this));
}

Ice&	Ice::operator=(const Ice& other)
{
	return (*this);
}