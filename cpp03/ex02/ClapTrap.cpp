#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : name("name")
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : name(name)
{
	std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& other )
{
	if (this != &other)
	{
		name = other.name;
		hp = other.hp;
		atkDmg = other.atkDmg;
		energy = other.energy;
	}
	return (*this);
}

ClapTrap::ClapTrap( const ClapTrap& other ) : name(other.name), hp(other.hp), atkDmg(other.atkDmg), energy(other.energy)
{
	std::cout << "Copy constructor called"<<std::endl;
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