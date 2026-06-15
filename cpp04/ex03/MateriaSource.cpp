#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called\n";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
	std::cout << "MateriaSource copy constructor called\n";
	for (int i = 0; i < 4; i++)
	{
		if (materiaSource._inventory[i])
			_inventory[i] = materiaSource._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
	std::cout << "MateriaSource assignment operator called\n";
	if (this != &materiaSource)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			if (materiaSource._inventory[i])
				_inventory[i] = materiaSource._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << "MateriaSource destructor called\n";
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if ((this->_inventory)[i] == NULL)
		{
			(this->_inventory)[i] = m;
			std::cout << "MateriaSource learned " << m->getType() << " materia\n";
			return;
		}
	}
	std::cout << "MateriaSource inventory is full, cannot learn more materia\n";
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
		{
			std::cout << "MateriaSource created " << type << " materia\n";
			return _inventory[i]->clone();
		}
	}
	std::cout << "MateriaSource does not know how to create " << type << " materia\n";
	return NULL;
}
