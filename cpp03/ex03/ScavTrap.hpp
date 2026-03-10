#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
	#include "ClapTrap.hpp"

	class ScavTrap : public ClapTrap
	{
		public:
			ScavTrap&	operator=(const ScavTrap& other);
			ScavTrap( const ScavTrap& other );
			ScavTrap( void );
			ScavTrap( std::string name );
			~ScavTrap( void );
			void	attack( const std::string& target ) override;
			void	guardGate( void );
	};
#endif