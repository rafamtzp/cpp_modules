#include <iostream>

std::string	uppercase(std::string s)
{
	for (int i = 0; i < s.length(); i++)
		s[i] = std::toupper(s[i]);
	return s;
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; argv[i] && argc > 1; i++)
		std::cout << uppercase(std::string(argv[i])) << " ";
	if (argc > 1)
		std::cout << "\b" << std::endl;
}
