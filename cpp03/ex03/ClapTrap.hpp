#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
	#include <iostream>

	class ClapTrap
	{
		protected:
			std::string name;
			int hp;
			int energy;
			int atkDmg;
			ClapTrap&	operator=( const ClapTrap& other );
			ClapTrap( const ClapTrap& other );
		
		public:
			ClapTrap( void );
			ClapTrap( std::string name );
			~ClapTrap( void );
			void	attack(const std::string& target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
	};
#endif
