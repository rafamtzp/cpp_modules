#include "Animal.hpp"
Animal::Animal( void ) {}
Animal::Animal( std::string type ) : type(type){}
Animal::Animal( const Animal& other ) : type(other.type){}
Animal::~Animal( void ) {}
Animal& Animal::operator=( const Animal& other )
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}