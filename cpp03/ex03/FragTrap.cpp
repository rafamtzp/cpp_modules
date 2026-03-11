#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	hp = 100;
	energy = 100;
	atkDmg = 30;
	std::cout << "Fragtrap created" << std::endl;
}

FragTrap::FragTrap( std::string name )
{
	hp = 100;
	energy = 100;
	atkDmg = 30;
	std::cout << "FragTrap " << name << " was created." << std::endl;
}

FragTrap::FragTrap( const FragTrap& other )
{
	hp = other.hp;
	energy = other.energy;
	atkDmg = other.atkDmg;
	std::cout<<"FragTrap copy created"<<std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		hp = other.hp;
		energy = other.energy;
		atkDmg = other.atkDmg;
	}
	return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destroyed" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "Who's up for a high five?" << std::endl;
}
