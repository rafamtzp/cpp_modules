#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
	#include <iostream>

	class Zombie
	{
		private:
			std::string	name;
		
		public:
			Zombie( void );
			Zombie( std::string );
			~Zombie( void );
			void setName( std::string );
			void announce(void) const;
	};
#endif