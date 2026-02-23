#include "Point.hpp"

Point::Point(void) : x(0), y(0){}
Point::Point( const float f1, const float f2 ) : x(Fixed(f1)), y(Fixed(f2)){}
Point::Point( const Point& other ) : x(other.x), y(other.y){}
Point::~Point(){}

Point&  Point::operator=( const Point& other )
{
    if (this != &other)
    {
        this->x = other.x;
        
    }
    return (*this);
}

const Fixed Point::getx( void ) const { return (x); }
const Fixed Point::gety( void ) const { return (y); }