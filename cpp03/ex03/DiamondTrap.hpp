#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP
	#include "FragTrap.hpp"
	#include "ScavTrap.hpp"

	class DiamondTrap: public ScavTrap, public FragTrap
	{
		private:
			std::string name;

		public:
			DiamondTrap(void);
			DiamondTrap(std::string name);
			~DiamondTrap(void);
			void	attack(const std::string& target);
			void	whoAmI(void);
	};
#endif
