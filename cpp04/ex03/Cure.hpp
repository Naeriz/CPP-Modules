#pragma once

#include "AMateria.hpp"

class Cure : public AMateria{
protected:
	std::string _type;
public:
	Cure();
	Cure(const Cure& cpyfrom);
	Cure& operator=(const Cure& cpyfrom);
	virtual ~Cure();
	std::string const & getType() const;

	AMateria* clone() const;
	void use(ICharacter& target);
};