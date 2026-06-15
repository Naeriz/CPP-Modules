#include "Animal.hpp"

Animal::Animal() : _type("default")
{
	std::cout << "Animal default has been constructed\n";
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal " << _type << " has been constructed\n";
}

Animal::Animal(const Animal&  cpyfrom)
{
	_type = cpyfrom._type;
	std::cout << "Copy constructor has been called\n";
}

Animal	&Animal::operator=(const Animal& cpyfrom)
{
	_type = cpyfrom._type;
	std::cout << "assignment operator has been called\n";
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal has been destructed\n";
}

void Animal::makeSound() const
{
	std::cout << "RAHH\n";
}

std::string Animal::getType() const
{
	return (_type);
}