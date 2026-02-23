#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;

    public:
    // Constructors and destructors
        Point( void );
        Point( const float f1, const float f2 );
        Point( const Point& other );
        ~Point( void );
    // Operators
        Point&  operator=( const Point& other );
        const Fixed getx( void ) const;
        const Fixed gety( void ) const;
};

