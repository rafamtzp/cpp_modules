#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
	#include <iostream>

	class ClapTrap
	{
		private:
			std::string name;
			int hp = 10;
			int energy = 10;
			int atkDmg = 0;
			
		public:
			ClapTrap&	operator=( const ClapTrap& other );
			ClapTrap( const ClapTrap& other );
			ClapTrap( void );
			ClapTrap( std::string name );
			~ClapTrap( void );
			void	attack(const std::string& target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);

		// for tests
		void	getValues(void);
	};
#endif
