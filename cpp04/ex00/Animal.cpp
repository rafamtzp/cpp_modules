#include "Animal.hpp"

Animal::Animal( void ) : type("Animal")
{
	std::cout <<
	"Animal created"
	<<std::endl;
}

Animal::Animal( const Animal& other ) : type(other.type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}
Animal::~Animal( void )
{
	std::cout <<"Animal destroyed"<<std::endl;
}
Animal& Animal::operator=( const Animal& other )
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (type);
}

void	Animal::makeSound(void) const
{
	std::cout << "* Unidentified animal noises *"<<std::endl;
}
