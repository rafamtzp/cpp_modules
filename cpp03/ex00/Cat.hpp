#include "Animal.hpp"

class Cat : public Animal
{
    private:

    public:
        Cat( void );
        Cat( Cat& other );
        ~Cat( void );
        Cat& operator=( const Cat& other );
        makeSound( void );
}

#include "Cat.hpp"

Cat::Cat(void) 