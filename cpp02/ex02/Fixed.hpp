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
#include <iostream>

class Fixed
{
	private:
		int _value;
		static const int _width;

	public:
	// Constructors and destructors
		Fixed();
		Fixed(const Fixed& other);
		Fixed( const int n );
		Fixed( const float f );
		~Fixed();

	// Member functions
		float	toFloat( void ) const;
		int	toInt( void ) const;
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );

	// Operators
		Fixed&	operator=( const Fixed& other );
		bool	operator<(const Fixed& other) const;
		bool	operator>(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;
		Fixed&	operator++( void ); //pre-increment
		Fixed	operator++( int ); //post-increment
		Fixed&	operator--( void ); //pre-decrement
		Fixed	operator--( int ); //post-decrement
		friend std::ostream&	operator<<( std::ostream& out , Fixed& num );
		friend std::ostream&	operator<<( std::ostream& out , const Fixed& num );
};


