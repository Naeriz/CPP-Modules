#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	std::cout << "AMateria default has been constructed\n";
}

AMateria::AMateria(std::string const &type) : _type(type)//ref to avoid copy but doesnt matter much on this scale
{
	std::cout << "AMateria " << _type << " has been constructed\n";
}

AMateria::AMateria(const AMateria&  cpyfrom)
{
	(void)cpyfrom;
	//no type copying cuz subject hint
	std::cout << "Copy constructor has been called\n";
}

AMateria	&AMateria::operator=(const AMateria& cpyfrom)
{
	(void)cpyfrom;
	std::cout << "assignment operator has been called\n";
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria has been destructed\n";
}

std::string const &AMateria::getType() const //to return original string not cpy //once again why not sooner
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}