#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
	#include <iostream>

	class ClapTrap
	{
		protected:
			std::string name;
			int hp = 100;
			int energy = 100;
			int atkDmg = 30;
			
		public:
			ClapTrap&	operator=( const ClapTrap& other );
			ClapTrap( const ClapTrap& other );
			ClapTrap( void );
			ClapTrap( std::string name );
			virtual ~ClapTrap( void );
			virtual void	attack(const std::string& target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
	};
#endif


