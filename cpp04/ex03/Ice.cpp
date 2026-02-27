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
	std::cout
	<<"* shoots ice bolt at "<<target.getName()<<" *"
	<<std::endl;
}

AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

Ice&	Ice::operator=(const Ice& other)
{
	return (*this);
}