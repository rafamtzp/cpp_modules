#ifndef WRONGWrongAnimal_HPP
#define WRONGWrongAnimal_HPP
	#include <iostream>

	class WrongAnimal
	{
		protected:
			std::string type;
		public:
			WrongAnimal( void );
			WrongAnimal( std::string type );
			WrongAnimal( const WrongAnimal& other );
			virtual ~WrongAnimal( void );
			WrongAnimal& operator=( const WrongAnimal& other );
			std::string	getType(void) const;
			void	makeSound(void) const;
	};
#endif