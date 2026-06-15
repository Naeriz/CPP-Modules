#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "Dog default has been constructed\n";
}

Dog::Dog(std::string _type) : Animal(_type)
{
	_type = "Dog";
	std::cout << "Dog " << _type << " has been constructed\n";
}

Dog::Dog(const Dog& cpyfrom) : Animal(cpyfrom)
{
	std::cout << "Copy constructor has been called\n";
}

Dog &Dog::operator=(const Dog& cpyfrom)
{
	if (this != &cpyfrom)
		Animal::operator=(cpyfrom);
	std::cout << "Dog assignment operator has been called\n";
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog has been destructed\n";
}

void Dog::makeSound() const
{
	std::cout << "WOOF\n";
}