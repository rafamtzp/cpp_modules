#ifndef HUMANA_HPP
#define HUMANA_HPP
	#include "Weapon.hpp"
	#include <iostream>

	class	HumanA
	{
		private:
			std::string name;
			Weapon& r_weapon;
		
		public:
			HumanA(std::string name, Weapon& r_weapon);
			~HumanA();
			void	attack();
	};
#endif