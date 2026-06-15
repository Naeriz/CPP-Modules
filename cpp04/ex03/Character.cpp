#include "Character.hpp"

Character::Character() : _name("Default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Default Character has been created\n";
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character " << _name << " has been created\n";
}

Character::Character(const Character &src) : _name(src._name)
{
	std::cout << "Character " << _name << " has been copied\n";
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &src)
{
	std::cout << "Character " << _name << " has been assigned\n";
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << "Character " << _name << " has been destroyed\n";
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "Character " << _name << " cannot equip NULL\n";
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "Character " << _name << " has equipped " << m->getType() << "\n"; // getType pas content
			return;
		}
	}
	std::cout << "Character " << _name << "'s inventory is full\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || this->_inventory[idx] == NULL)
	{
		std::cout << "Character " << this->_name << " cannot unequip already empty or non existent slots\n";
		return;
	}
	std::cout << "Character " << this->_name << " has unequipped " << this->_inventory[idx]->getType() << "\n";
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || this->_inventory[idx] == NULL)
	{
		std::cout << "Character " << this->_name << " cannot use this slot of the inventory\n";
		return;
	}
	this->_inventory[idx]->use(target);
}

AMateria	*Character::getMateriaFromInventory(int idx) const
{
	if (idx < 0 || idx >= 4)
		return NULL;
	return this->_inventory[idx];
}