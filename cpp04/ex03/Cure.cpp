#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	_type = "cure";
	std::cout << "Cure default has been constructed\n";
}

Cure::Cure(const Cure&  cpyfrom) : AMateria(_type)
{
	_type = cpyfrom._type;
	std::cout << "Copy constructor has been called\n";
}

Cure	&Cure::operator=(const Cure& cpyfrom)
{
	if (this != &cpyfrom)
		_type = cpyfrom._type;
	std::cout << "assignment operator has been called\n";
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure has been destructed\n";
}

std::string const &Cure::getType() const //to return original string not cpy //once again why not sooner
{
	return (_type);
}

AMateria *Cure::clone() const
{
	return (new Cure());
}


void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}