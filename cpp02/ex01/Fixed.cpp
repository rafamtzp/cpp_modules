#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_width = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

Fixed::Fixed( const int n ) : _value(n * pow(2, 8))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float f ) : _value((int)roundf(f * (1 << _width)))
{
	std::cout << "Raw value from float: "<<_value<<std::endl;
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat( void ) const
{
	return (_value / (float)pow(2, 8));
}

int	Fixed::toInt( void ) const
{
	return ((int)roundf(_value / (float)pow(2, 8)));
}

std::ostream&	operator<<( std::ostream& out , const Fixed& num )
{
	return (out << num.toFloat());
}

std::ostream&	operator<<( std::ostream& out , Fixed& num )
{
	return (out << num.toFloat());
}

