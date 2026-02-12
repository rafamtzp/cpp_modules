
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& r_weapon):
r_weapon(r_weapon), name(name)
{}

HumanA::~HumanA(){}

void	HumanA::attack()
{
	std::cout
	<< name << " attacks with their " << r_weapon.getType() <<
	std::endl;
}