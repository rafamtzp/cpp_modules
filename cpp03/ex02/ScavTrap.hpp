#include "ClapTrap.hpp"

// • Name, which is passed as a parameter to the constructor
// • Hit points (100), representing the health of the ClapTrap
// • Energy points (50)
// • Attack damage (20)

class ScavTrap : public ClapTrap
{
	private:
		ScavTrap&	operator=(const ScavTrap& other);
		ScavTrap( const ScavTrap& other );

	public:
		ScavTrap(void);
		ScavTrap( std::string name );
		~ScavTrap(void);
		void guardGate( void );
};