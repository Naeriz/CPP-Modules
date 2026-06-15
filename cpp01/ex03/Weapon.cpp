#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {} //type given by main calling the constructor

Weapon::~Weapon() {}

const std::string &Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType(std::string new_type)
{
	_type = new_type;
}
