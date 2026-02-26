#include "Brain.hpp"

Brain::Brain(void)
{
	ideas = new std::string[100];
	std::cout << "Brain created" << std::endl;
}

Brain::~Brain(void)
{
	delete [] ideas;
	std::cout << "Brain destroyed" << std::endl;
}

Brain::Brain(const Brain& other)
{
	ideas = new std::string[100];
	for (int i = 0; i < 100 && ideas != NULL; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy created" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100 && ideas != NULL; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}