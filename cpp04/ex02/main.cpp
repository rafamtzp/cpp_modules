#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *pets[2];

	// Dog doggo = Dog();
	// Cat catto = Cat();
	// pets[0] = &doggo;
	// pets[1] = &catto;

	pets[0] = new Dog;
	pets[1] = new Cat;

	pets[0]->makeSound();
	pets[1]->makeSound();

	//Cat *twin_catto = new Cat((const Cat&)*pets[1]);

	delete pets[0];
	delete pets[1];
	//delete twin_catto;

	// TEST FOR EX02
	// Animal uninstantiable;

	return 0;
}