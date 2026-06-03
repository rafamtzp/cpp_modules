#include "ScalarConverter.hpp"

int main(int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid input" << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
}
