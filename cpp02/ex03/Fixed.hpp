#ifndef FIXED_HPP
#define FIXED_HPP
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
			static Fixed&	min(Fixed& num1, Fixed& num2);
			static const Fixed&	min(const Fixed& num1, const Fixed& num2);
			static Fixed&	max(Fixed& num1, Fixed& num2);
			static const Fixed&	max(const Fixed& num1, const Fixed& num2);
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
		};
	std::ostream&	operator<<( std::ostream& out , Fixed& num );
	std::ostream&	operator<<( std::ostream& out , const Fixed& num );
#endif


