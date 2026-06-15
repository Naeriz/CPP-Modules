#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {} //have to set weapon to null otherwise wont compile

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	_weapon = &new_weapon;
}

void	HumanB::attack()
{
	if (_weapon == NULL)
	{
		std::cout << _name << " punches\n";
	}
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}