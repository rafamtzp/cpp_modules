// • Private members:
// ◦ A Fixed const attribute x.
// ◦ A Fixed const attribute y.
// ◦ Anything else useful.
// • Public members:
// ◦ A default constructor that initializes x and y to 0.
// ◦ A constructor that takes two constant floating-point numbers as parameters.
// It initializes x and y with those parameters.
// ◦ A copy constructor.
// ◦ A copy assignment operator overload.
// ◦ A destructor.
// ◦ Anything else useful.
#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;

    public:
        Point( void );
        Point( const float f1, const float f2 );
        Point( )

};