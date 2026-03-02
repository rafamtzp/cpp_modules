#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	inventory = new AMateria *[4];
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	std::cout <<"MateriaSource created"<<std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i];
	}
	std::cout<<"MateriaSource copy created"<<std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	delete [] inventory;
	std::cout<<"MateriaSource destroyed"<<std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
		}
		delete [] inventory;
		inventory = new AMateria*[4];
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
			{
				inventory[i] = other.inventory[i];
			}
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4 && inventory; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = materia;
			break ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4 && inventory; i++)
	{
		if (inventory[i] && inventory[i]->getType() == type)
			return(inventory[i]->clone());
	}
	return (0);
}