#ifndef	HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
	std::string _name;
	Weapon		*_weapon; //need ptr to set to NULL or no compile cuz empty field
public:
	HumanB(std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon &new_Weapon);
};

#endif