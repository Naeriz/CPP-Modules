#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
private:
	AMateria	*_inventory[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	virtual ~MateriaSource();
	MateriaSource &operator=(const MateriaSource &src);

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};