#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie( void )
{
	return ;
}

void	Zombie::announce( void )
{
	std::cout
	<< name << ": "
	<< "BraiiiiiiinnnzzzZ..."
	<< std::endl;
}