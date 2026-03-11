#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap s("bob");

	s.guardGate();
	s.attack("bill");
	s.takeDamage(5);
	s.beRepaired(2);
	s.getValues();
}