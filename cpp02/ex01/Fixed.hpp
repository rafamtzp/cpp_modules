// Add the following public constructors and public member functions to your class:
// • A constructor that takes a constant integer as a parameter.
// It converts it to the corresponding fixed-point value. The fractional bits value
// should be initialized to 8, like in exercise 00.
// • A constructor that takes a constant floating-point number as a parameter.
// It converts it to the corresponding fixed-point value. The fractional bits value
// should be initialized to 8, like in exercise 00.
// • A member function float toFloat( void ) const;
// that converts the fixed-point value to a floating-point value.
// • A member function int toInt( void ) const;
// that converts the fixed-point value to an integer value.
// And add the following function to the Fixed class files:
// • An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as a parameter

class Fixed
{
	private:
		int _value;
		static const int _width;

	public:
		Fixed();
		Fixed(Fixed& other);
		Fixed( const int n );

		Fixed&	operator=( Fixed& other );
		~Fixed();
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
};

Fixed::Fixed( const int n ) : _value(n * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2){}

