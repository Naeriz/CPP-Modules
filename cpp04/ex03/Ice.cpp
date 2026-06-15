#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	_type = "ice";
	std::cout << "Ice default has been constructed\n";
}

Ice::Ice(const Ice&  cpyfrom) : AMateria(_type)
{
	_type = cpyfrom._type;
	std::cout << "Copy constructor has been called\n";
}

Ice	&Ice::operator=(const Ice& cpyfrom)
{
	if (this != &cpyfrom)
		_type = cpyfrom._type;
	std::cout << "assignment operator has been called\n";
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice has been destructed\n";
}

std::string const &Ice::getType() const //to return original string not cpy //once again why not sooner
{
	return (_type);
}

AMateria *Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*\n";
}