#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie *ptr;

	randomChump("Chump");
	ptr = newZombie("Allocson");
	ptr->announce();
	delete ptr;
}
