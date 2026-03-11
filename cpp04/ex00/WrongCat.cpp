#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	type = "WrongCat";
	std::cout << "WrongCat created"<<std::endl;
}

WrongCat::WrongCat( WrongCat& other )
{
	type = other.type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat destroyed" << std::endl;
}

WrongCat&	WrongCat::operator=( const WrongCat& other )
{
	if (this != &other)
		type = other.type;
	return (*this);
}


void	WrongCat::makeSound( void ) const
{
	std::cout << "meow but sus" << std::endl;
}