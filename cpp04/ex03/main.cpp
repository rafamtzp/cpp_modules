#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

void	almost_basic_test();
void	inventory_overflow();
void	deep_copies();
void	assignment_operator();
void	invalid_index();
void	unknown_materia();
void	last_test();

int main()
{
	almost_basic_test();
	std::cout << std::string(45, '-')<<std::endl;
	inventory_overflow();
	std::cout << std::string(45, '-')<<std::endl;
	deep_copies();
	std::cout << std::string(45, '-')<<std::endl;
	assignment_operator();
	std::cout << std::string(45, '-')<<std::endl;
	invalid_index();
	std::cout << std::string(45, '-')<<std::endl;
	unknown_materia();
	std::cout << std::string(45, '-')<<std::endl;
	last_test();

}

void almost_basic_test()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria **created = new AMateria*[10];
	AMateria* tmp;
	tmp = src->createMateria("ice");
	created[0] = tmp;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	created[1] = tmp;
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);
	me->unequip(1);
	me->unequip(3);
	me->unequip(40);

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(3, *bob);

	for (int i = 0; i < 2; i++)
		delete created[i];
	delete [] created;
	delete bob;
	delete me;
	delete src;
}

void	inventory_overflow()
{

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");

	for (int i = 0; i < 6; i++)
	{
		AMateria* tmp = src->createMateria("ice");
		me->equip(tmp);
		if (i >= 4)
			delete tmp;
	}

	delete me;
	delete src;
}

void deep_copies()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	Character* original = new Character("original");

	AMateria* tmp = src->createMateria("ice");
	original->equip(tmp);

	Character* copy = new Character(*original);

	std::cout << "Using original:\n";
	original->use(0, *original);

	std::cout << "Using copy:\n";
	copy->use(0, *copy);

	delete original;
	delete copy;
	delete src;
}

void assignment_operator()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character a("A");
	Character b("B");

	a.equip(src->createMateria("ice"));
	a.equip(src->createMateria("cure"));

	b = a;

	std::cout << "Using b after assignment:\n";
	b.use(0, b);
	b.use(1, b);

	delete src;
}

void invalid_index()
{
	Character me("me");
	Character bob("bob");

	me.use(-1, bob);
	me.use(4, bob);
	me.unequip(10);
}
void unknown_materia()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	AMateria* tmp = src->createMateria("fire");

	if (!tmp)
		std::cout << "Unknown materia handled correctly\n";

	delete src;
}

void last_test()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character a("A");
	Character b("B");

	for (int i = 0; i < 4; i++)
		a.equip(src->createMateria("ice"));

	b = a;

	Character c(a);

	for (int i = 0; i < 4; i++)
	{
		a.use(i, b);
		b.use(i, a);
		c.use(i, a);
	}
	delete src;
}