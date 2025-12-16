#include <iostream>

char *uppercase(char *s)
{
	for (int i = 0; s[i]; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	}
	return s;
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; argv[i]; i++)
		std::cout << uppercase(argv[i]) << " ";
	std::cout << "\b" << std::endl;
}
