#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name"), ScavTrap(), FragTrap()
{
	energy = 50;
	std::cout << "DiamondTrap created" << std::endl;
	std::cout << "Values: "<<hp<<" "<<energy<<" "<<atkDmg<<std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
{
	energy = 50;
	std::cout << "DiamondTrap "<<name<<" created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
	hp = other.hp;
	energy = other.energy;
	atkDmg = other.atkDmg;
	std::cout<<"DiamondTrap copy created"<<std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		hp = other.hp;
		energy = other.energy;
		atkDmg = other.atkDmg;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destroyed" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Name: "<<name<<std::endl;
	std::cout << "ClapTrap Name: "<<ClapTrap::name<<std::endl;
}