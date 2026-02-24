#include "FragTrap.cpp"
#include "ScavTrap.cpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		~DiamondTrap(void);
		void	whoAmI(void);
};
