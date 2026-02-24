#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap t("trap");

	t.attack("enemy1");
	t.beRepaired(10);
	t.takeDamage(10);
}