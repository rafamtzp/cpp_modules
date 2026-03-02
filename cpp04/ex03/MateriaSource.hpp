#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
	#include "IMateriaSource.hpp"
	class MateriaSource : public IMateriaSource
	{
		private:
			AMateria **inventory;
		public:
			MateriaSource(void);
			MateriaSource(const MateriaSource& other);
			~MateriaSource(void);
			MateriaSource& operator=(const MateriaSource& other);
			void learnMateria(AMateria* materia);
			AMateria* createMateria(std::string const & type);
	};
#endif

