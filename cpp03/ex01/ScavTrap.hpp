#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
	#include "ClapTrap.hpp"

	class ScavTrap : public ClapTrap
	{
		private:
			ScavTrap&	operator=(const ScavTrap& other);
			ScavTrap( const ScavTrap& other );

		public:
			ScavTrap( void );
			ScavTrap( std::string name );
			~ScavTrap( void );
			void	attack( const std::string& target ) override;
			void	guardGate( void );
	};
#endif