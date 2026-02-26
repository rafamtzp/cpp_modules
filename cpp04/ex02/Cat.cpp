#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat created"<<std::endl;
	type = "cat";
	brain = new Brain;
}

Cat::Cat( const Cat& other )
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Cat::~Cat( void )
{
	delete brain;
	std::cout << "Cat destroyed" << std::endl;
}

Cat&	Cat::operator=( const Cat& other )
{
	if (this != &other)
	{
		delete brain;
		brain = new Brain(*other.brain);
		type = other.type;
	}
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << "meow" << std::endl;
}
