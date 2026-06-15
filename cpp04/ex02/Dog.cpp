#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "Dog default has been constructed\n";
	_brain = new Brain();
}

Dog::Dog(std::string _type) : Animal(_type)
{
	_type = "Dog";
	std::cout << "Dog " << _type << " has been constructed\n";
	_brain = new Brain();
}

Dog::Dog(const Dog& cpyfrom) : Animal(cpyfrom)
{
	_brain = new Brain(*cpyfrom._brain);
	std::cout << "Copy constructor has been called\n";
}

Dog &Dog::operator=(const Dog& cpyfrom)
{
	if (this != &cpyfrom)
	{
		Animal::operator=(cpyfrom);
		delete _brain;
		_brain = new Brain(*cpyfrom._brain);
	}
	std::cout << "Dog assignment operator has been called\n";
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog has been destructed\n";
}

void Dog::makeSound() const
{
	std::cout << "WOOF\n";
}

Brain *Dog::getBrain() const
{
	return (_brain);
}