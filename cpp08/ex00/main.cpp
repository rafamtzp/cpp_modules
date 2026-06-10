#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(void)
{
	std::vector<int> vec;

	for (int i = 1; i < 6; i++)
		vec.push_back(i);

	std::cout << "vector values: ";
	for (int i = 0; i < 5; i++)
		std::cout << vec[i] << ", ";
	std::cout << std::endl;

	std::cout << "\n--- TESTING EASYFIND ---" << std::endl;
	try
	{
		std::cout << "Looking for 3:" << std::endl;
		std::cout <<
		"number found: " << *easyfind(vec, 3) << std::endl;
	
		std::cout << "Trying to find 42: " << std::endl;
		std::cout << *easyfind(vec, 42) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}