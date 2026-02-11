#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB(void){}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

void	HumanB::attack(void)
{
	std::cout
	<< name << " attacks with their " << weapon.getType() <<
	std::endl;
}