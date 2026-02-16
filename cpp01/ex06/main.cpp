#include "Harl.hpp"

static int	getIntLevel(std::string level)
{
	if (level == "DEBUG")
		return 1;
	else if (level == "INFO")
		return 2;
	else if (level == "WARNING")
		return 3;
	else if (level == "ERROR")
		return 4;
	return 5;
}

int main(int argc, char **argv)
{
	if (!argv[1])
		return 1;
	Harl harl;
	int lvl = getIntLevel(argv[1]);
	std::cout << lvl << std::endl;
	switch (lvl)
	{
		case 1:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			lvl++;
		case 2:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			lvl++;
		case 3:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			lvl++;
		case 4:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			break ;
		case 5:
			std::cout << 
			"[ Probably complaining about insignificant problems ]"
			<< std::endl;
			break ;
	}
}
