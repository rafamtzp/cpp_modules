#include "Weapon.hpp"

Weapon::Weapon(void)
{
	type = "bare hand";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}
Weapon::~Weapon(void)
{
	return ;
}
const std::string&	Weapon::getType(void) const
{
	return (type);
}

void	Weapon::setType(std::string newtype)
{
	type = newtype;
}