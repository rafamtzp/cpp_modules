#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
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