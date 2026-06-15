#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat default has been constructed\n";
}

Cat::Cat(std::string _type) : Animal(_type)
{
	_type = "Cat";
	std::cout << "Cat " << _type << " has been constructed\n";
}

Cat::Cat(const Cat& cpyfrom) : Animal(cpyfrom)
{
	std::cout << "Copy constructor has been called\n";
}

Cat &Cat::operator=(const Cat& cpyfrom)
{
	if (this != &cpyfrom)
		Animal::operator=(cpyfrom);
	std::cout << "Cat assignment operator has been called\n";
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat has been destructed\n";
}

void Cat::makeSound() const
{
	std::cout << "MEOWWWRHG\n";
}