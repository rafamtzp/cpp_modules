#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}
Weapon::~Weapon(void)
{
	return ;
}
std::string	Weapon::getType(void) const
{
	return (type);
}

void	Weapon::setType(std::string newtype)
{
	
}