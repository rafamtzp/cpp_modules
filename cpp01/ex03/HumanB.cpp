#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	p_weapon = NULL;
}

HumanB::~HumanB(void){}

void	HumanB::setWeapon(Weapon& weapon)
{
	p_weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (p_weapon)
	{
		std::cout
		<< name << " attacks with their " << p_weapon->getType() <<
		std::endl;
	}
	else
		std::cout << name << " has no weapon to attack!" << std::endl;
}