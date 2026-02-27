#ifndef ICE_HPP
#define ICE_HPP
	#include "AMateria.hpp"

	class Ice : public AMateria
	{
		public:
			Ice(void);
			~Ice(void);
			Ice(const Ice& other);
			void	use(ICharacter& target) override;
			AMateria* clone() const;
			Ice& operator=(const Ice& other);
	};
#endif

