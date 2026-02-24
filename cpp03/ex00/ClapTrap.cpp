#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : name("name"), hp(10), energy(10), atkDmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : name(name), energy(10), atkDmg(0), hp(10)
{
	std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	hp -= amount;
	std::cout <<
	"ClapTrap " << name << " lost " << amount << " hp!"
	<< std::endl;
}

void	ClapTrap::attack( const std::string& target )
{
	if (energy > 0)
	{
		energy--;
		std::cout <<
		"ClapTrap " << name << " attacks " << target << ", causing "<< atkDmg << " points of damage!"
		<< std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy > 0)
	{
		energy--;
		hp += amount;
		std::cout <<
		"ClapTrap " << name << " has replenished " << amount << " hp points."
		<< std::endl;
	}
}