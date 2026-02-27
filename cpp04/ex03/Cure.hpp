#ifndef CURE_HPP
#define CURE_HPP
	#include "AMateria.hpp"

	class Cure : public AMateria
	{
		public:
			Cure(void);
			~Cure(void);
			Cure(const Cure& other);
			void	use(ICharacter& target) override;
			AMateria* clone() const;
			Cure& operator=(const Cure& other);
	};
#endif