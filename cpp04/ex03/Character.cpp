#include "Character.hpp"

Character::Character(void)
{
	inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	std::cout << "Character created" << std::endl;
}

Character::Character(const Character& other)
{
	inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	name = other.name;
	std::cout <<"Character copied"<<std::endl;
}

Character::Character(const std::string name)
{
	inventory = new AMateria *[4];
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	this->name = name;
	std::cout<<"Character "<<name<<" created"<<std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	delete [] inventory;
	std::cout<<"Character "<<name<<" destroyed"<<std::endl;
}

Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
		}
		delete [] inventory;
		inventory = new AMateria *[4];
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
		name = other.name;
	}
	return (*this);
}

std::string const&	Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria* m)
{
	if (!m || (m->getType() != "ice" && m->getType() != "cure"))
	{
		std::cout << "NOT VALID EQUIP"<<std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout <<m->getType()<<" equipped"<<std::endl;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && inventory[idx])
	{
		std::cout<<inventory[idx]<<" unequipped"<<std::endl;
		inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}