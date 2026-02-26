#ifndef ANIMAL_HPP
#define ANIMAL_HPP
	#include <iostream>

	class Animal
	{
		protected:
			std::string type;
		public:
			Animal( void );
			Animal( std::string type );
			Animal( const Animal& other );
			virtual ~Animal( void );
			Animal& operator=( const Animal& other );
			std::string	getType(void) const;
			virtual void	makeSound(void) const = 0;
	};
#endif