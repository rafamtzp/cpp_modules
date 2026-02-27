#ifndef CHARACTER_HPP
#define CHARACTER_HPP
	#include "ICharacter.hpp"
	#include "AMateria.hpp"

	class Character : public ICharacter
	{
		private:
			AMateria **inventory;
			std::string name;
		public:
			Character(void);
			Character(const Character& other);
			~Character(void);
			Character&	operator=(const Character& other);
			std::string const & getName() const;
			void equip(AMateria* m);
			void unequip(int idx);
			void use(int idx, ICharacter& target);

	};
#endif

Character::Character(void)
{
	inventory = new AMateria*[4];
	std::cout << "Character created" << std::endl;
}

Character::Character(const Character& other)
{
	inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		inventory[i] = other.inventory[i]->clone();
	std::cout <<"Character copied"<<std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)

	delete [] inventory;
	std::cout<<"Character destroyed"<<std::endl;
}

Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		// copy the inventory
	}
	return (*this);
}