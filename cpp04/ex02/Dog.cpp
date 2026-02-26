#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog created" << std::endl;
	type = "Dog";
	brain = new Brain;
}

Dog::Dog( const Dog& other )
{
	std::cout << "Dog copy constructor called" << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Dog destroyed" << std::endl;
}

Dog&	Dog::operator=( const Dog& other )
{
	if (this != &other)
	{
		delete brain;
		brain = new Brain(*other.brain);
		type = other.type;
	}
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << "woof" << std::endl;
}