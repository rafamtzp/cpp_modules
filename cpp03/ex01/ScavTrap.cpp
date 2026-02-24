#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ){}
ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {}
ScavTrap::~ScavTrap(void){}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << name << " is now in gatekeeper mode." << std::endl;
}