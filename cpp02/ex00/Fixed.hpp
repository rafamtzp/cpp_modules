#ifndef FIXED_HPP
#define FIXED_HPP
	class Fixed
	{
		private:
			int _value;
			static const int _width;

		public:
			Fixed();
			Fixed(Fixed& other);
			Fixed&	operator=(Fixed& other);
			~Fixed();
			int	getRawBits( void ) const;
			void	setRawBits( int const raw );
	};
#endif
