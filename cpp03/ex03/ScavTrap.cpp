#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	hp = 100;
	energy = 50;
	atkDmg = 20;
	std::cout << "ScavTrap created" << std::endl;
}
ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	hp = 100;
	energy = 50;
	atkDmg = 20;
	std::cout << "ScavTrap " << name << " was created"<<std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap(other)
{
	hp = 100;
	energy = 50;
	atkDmg = 20;
	std::cout << "ScavTrap copy created"<<std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << name << " is now in gatekeeper mode." << std::endl;
}

void	ScavTrap::attack( const std::string& target )
{
	if (energy > 0)
	{
		energy--;
		std::cout <<
		"ScavTrap " << name << " attacks " << target << ", causing "<< atkDmg << " points of damage!"
		<< std::endl;
	}
}
