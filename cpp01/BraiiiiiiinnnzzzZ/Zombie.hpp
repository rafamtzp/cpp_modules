#include <iostream>

class Zombie
{
	private:
		std::string	name;
	
	public:
		Zombie( std::string );
		~Zombie( void );
		void announce(void);
};
