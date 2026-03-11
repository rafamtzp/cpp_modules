#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	//const Animal* meta = new Animal();
	const WrongAnimal * meta = new WrongAnimal();

	const Animal* j = new Dog();

	//const Animal* i = new Cat();
	const WrongAnimal *i = new WrongCat();
	const WrongCat	*i2 = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	j->makeSound();

	i->makeSound();
	i2->makeSound();

	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete i2;

	return 0;
}