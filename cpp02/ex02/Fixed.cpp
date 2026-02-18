#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_width = 8;

// constructors and destructors
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _value(n * pow(2, 8))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float f ) : _value((int)roundf(f * (1 << _width)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
// member functions
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

float	Fixed::toFloat( void ) const
{
	return (_value / (float)pow(2, 8));
}

int	Fixed::toInt( void ) const
{
	return ((int)roundf(_value / (float)pow(2, 8)));
}

// operators
Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

std::ostream&	operator<<( std::ostream& out , const Fixed& num )
{
	return (out << num.toFloat());
}

std::ostream&	operator<<( std::ostream& out , Fixed& num )
{
	return (out << num.toFloat());
}

bool	Fixed::operator<(const Fixed& other) const
{
	if (this->_value < other._value)
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed& other) const
{
	if (this->_value > other._value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& other) const
{
		if (this->_value <= other._value)
		return (true);
	return (false);
}


bool	Fixed::operator>=(const Fixed& other) const
{
	if (this->_value >= other._value)
		return (true);
	return (false);
}


bool	Fixed::operator!=(const Fixed& other) const
{
	if (this->_value != other._value)
		return (true);
	return (false);
}


bool	Fixed::operator==(const Fixed& other) const
{
	if (this->_value == other._value)
		return (true);
	return (false);
}

// FIX ALL OF THESE TOMORROW BC THEY'RE WRONG!!!!!!!!!!
Fixed	Fixed::operator+(const Fixed& other) const
{
	return (this->_value + other._value);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (this->_value - other._value);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return (this->_value * other._value);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return (this->_value / other._value);
}

Fixed&	Fixed::operator++( void ) //pre-increment
{
	this->
}

Fixed	operator++( void ) //post-increment

Fixed&	operator--( void ) //pre-decrement

Fixed	operator--( void ) //post-decrement

// • A static member function min that takes two references to fixed-point numbers as
// parameters, and returns a reference to the smallest one.

// • A static member function min that takes two references to constant fixed-point
// numbers as parameters, and returns a reference to the smallest one.

// • A static member function max that takes two references to fixed-point numbers as
// parameters, and returns a reference to the greatest one.

// • A static member function max that takes two references to constant fixed-point
// numbers as parameters, and returns a reference to the greatest one.

