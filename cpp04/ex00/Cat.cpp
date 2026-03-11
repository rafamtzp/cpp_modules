#include "Cat.hpp"

Cat::Cat(void)
{
	type = "Cat";
	std::cout << "Cat created"<<std::endl;
}

Cat::Cat( Cat& other )
{
	type = other.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "Cat destroyed" << std::endl;
}

Cat&	Cat::operator=( const Cat& other )
{
	if (this != &other)
		type = other.type;
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << "meow" << std::endl;
}
