#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
	#include "ScavTrap.hpp"

	class FragTrap : virtual public ClapTrap
	{
		public:
			FragTrap( const FragTrap& other );
			FragTrap& operator=( const FragTrap& other );
			FragTrap( void );
			FragTrap(std::string name);
			~FragTrap( void );
			void highFivesGuys( void );
	};
#endif
