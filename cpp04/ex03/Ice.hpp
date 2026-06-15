#pragma once

#include "AMateria.hpp"

class Ice : public AMateria{
protected:
	std::string _type;
public:
	Ice();
	Ice(const Ice& cpyfrom);
	Ice& operator=(const Ice& cpyfrom);
	virtual ~Ice(); //idk
	std::string const & getType() const;

	AMateria* clone() const;
	void use(ICharacter& target);
};