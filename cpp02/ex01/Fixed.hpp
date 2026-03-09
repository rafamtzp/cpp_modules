#ifndef FIXED_HPP
#define FIXED_HPP
	#include <iostream>

	class Fixed
	{
		private:
			int _value;
			static const int _width;

		public:
			Fixed();
			Fixed(const Fixed& other);
			Fixed( const int n );
			Fixed( const float f );
			~Fixed();

			float	toFloat( void ) const;
			int	toInt( void ) const;
			int	getRawBits( void ) const;
			void	setRawBits( int const raw );
			
			Fixed&	operator=( const Fixed& other );
	};
	std::ostream&	operator<<( std::ostream& out , const Fixed& num );
	std::ostream&	operator<<( std::ostream& out , Fixed& num );
#endif

