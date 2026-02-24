#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ){}
ScavTrap::~ScavTrap( void ){}
ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << name << " is now in gatekeeper mode." << std::endl;
}