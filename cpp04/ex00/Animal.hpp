#ifndef ANIMAL_HPP
#define ANIMAL_HPP
	#include <iostream>

	class Animal
	{
		private:
			std::string type;
		public:
			Animal( void );
			Animal( std::string type );
			Animal( const Animal& other );
			~Animal( void );
			Animal& operator=( const Animal& other );
	};
#endif