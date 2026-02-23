#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
        Point&  operator=( const Point& other );

    public:
    // Constructors and destructors
        Point( void );
        Point( const float f1, const float f2 );
        Point( const Point& other );
        Point( const Fixed x, const Fixed y);
        ~Point( void );

    // Getters
        const Fixed getx( void ) const;
        const Fixed gety( void ) const;
    
    // Operators
    Point   operator-( const Point& other );
};

