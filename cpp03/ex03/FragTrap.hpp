#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		FragTrap( const FragTrap& other );
		FragTrap& operator=( const FragTrap& other );
	public:
		FragTrap( void );
		FragTrap(std::string name);
		~FragTrap( void );
		void highFivesGuys( void );
};
