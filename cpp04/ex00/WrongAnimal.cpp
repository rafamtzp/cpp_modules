#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal")
{
	std::cout <<
	"WrongAnimal created"
	<<std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) : type(other.type)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal( void )
{
	std::cout <<"WrongAnimal destroyed"<<std::endl;
}
WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other )
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}

void	WrongAnimal::makeSound(void) const 
{
	std::cout << "* Unidentified extraterrestrial creature sounds *"<<std::endl;
}