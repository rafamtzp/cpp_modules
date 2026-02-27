#ifndef CAT_HPP
#define CAT_HPP
	#include "Animal.hpp"

	class Cat : public Animal
	{
		public:
			Cat( void );
			Cat( Cat& other );
			~Cat( void );
			Cat&	operator=( const Cat& other );
			void	makeSound( void ) const override;
	};
#endif
