#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
{
	std::cout << "DiamondTrap "<<name<<" created" << std::endl;
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