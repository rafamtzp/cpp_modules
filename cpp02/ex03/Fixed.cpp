#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_width = 8;

//------------ Constructors and destructors ----------------------

Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
	//std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _value(n * pow(2, 8))
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float f ) : _value((int)roundf(f * (1 << _width)))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

// ---------------- Member functions ---------------------------------

int	Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)_value / (1 << _width));
}

int	Fixed::toInt( void ) const
{
	return ((int)roundf(_value / (1 << _width)));
}

Fixed&	Fixed::min(Fixed& num1, Fixed& num2)
{
	if (num1._value <= num2._value)
		return (num1);
	return (num2); 
}

const Fixed&	Fixed::min(const Fixed& num1, const Fixed& num2)
{
	if (num1._value <= num2._value)
		return (num1);
	return (num2); 
}

Fixed&	Fixed::max(Fixed& num1, Fixed& num2)
{
	if (num1._value >= num2._value)
		return (num1);
	return (num2); 
}

const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2)
{
	if (num1._value >= num2._value)
		return (num1);
	return (num2); 
}

// ---------------- Operators ---------------------------------

Fixed&	Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
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

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed tmp(*this);

	tmp._value = this->_value + other._value;
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed tmp(*this);

	tmp._value = this->_value - other._value;
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed tmp(*this);

	tmp._value = (this->_value * other._value) >> _width;
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed tmp(*this);

	tmp._value = (this->_value << _width) / other._value;
	return (tmp);
}

Fixed&	Fixed::operator++( void ) //pre-increment
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++( int ) //post-increment
{
	Fixed cpy(*this);

	++(*this);
	return (cpy);
}

Fixed&	Fixed::operator--( void ) //pre-decrement
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--( int ) //post-decrement
{
	Fixed cpy(*this);

	--(*this);
	return (cpy);
}

