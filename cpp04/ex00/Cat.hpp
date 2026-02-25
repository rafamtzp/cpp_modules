#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat( void );
		Cat( Cat& other );
		~Cat( void );
		Cat&	operator=( const Cat& other );
		void	makeSound( void );
}

#include "Cat.hpp"

Cat::Cat(void)
{
	type = "cat";
}

Cat::Cat( Cat& other )
{
	type = other.type;
}

Cat&	Cat::operator=( const Cat& other )
{
	if (this != &other)
		type = other.type;
	return ()
}

void	Cat::makeSound( void )
{
	std::cout << "meow" << std::endl;
}
