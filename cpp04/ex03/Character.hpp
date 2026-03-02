#ifndef CHARACTER_HPP
#define CHARACTER_HPP
	#include "ICharacter.hpp"
	#include "AMateria.hpp"

	class Character : public ICharacter
	{
		private:
			std::string name;
		public:
			AMateria **inventory;
			Character(void);
			Character(const Character& other);
			Character(const std::string name);
			~Character(void);
			Character&	operator=(const Character& other);
			std::string const & getName() const;
			void equip(AMateria* m);
			void unequip(int idx);
			void use(int idx, ICharacter& target);
	};
#endif


