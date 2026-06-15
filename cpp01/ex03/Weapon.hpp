#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
private:
	std::string _type;
public:
	Weapon(std::string type);
	~Weapon();

	const std::string & getType() const; //needed const ref
	void		setType(std::string new_type);
};


#endif
