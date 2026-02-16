#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "debug message" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "info message" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "warning message" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "error message" << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs[4])(void) = {
		&Harl::debug, 
		&Harl::info, 
		&Harl::warning, 
		&Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			(this->*funcs[i])();
	}
}
