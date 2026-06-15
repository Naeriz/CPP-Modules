#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter{
private:
	const std::string	_name;
	AMateria			*_inventory[4];
	int					_count;

public:
	Character();
	Character(std::string const &name);
	Character(const Character &character);
	Character &operator=(const Character &character);
	~Character();

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
	AMateria *getMateriaFromInventory(int idx) const;
};