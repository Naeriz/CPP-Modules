#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default")
{
	std::cout << "WrongAnimal default has been constructed\n";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal " << _type << " has been constructed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal&  cpyfrom)
{
	_type = cpyfrom._type;
	std::cout << "Copy constructor has been called\n";
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& cpyfrom)
{
	_type = cpyfrom._type;
	std::cout << "assignment operator has been called\n";
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal has been destructed\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "RAHH\n";
}

std::string WrongAnimal::getType() const
{
	return (_type);
}