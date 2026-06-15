#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat default has been constructed\n";
	_brain = new Brain();
}

Cat::Cat(std::string _type) : Animal(_type)
{
	_type = "Cat";
	std::cout << "Cat " << _type << " has been constructed\n";
	_brain = new Brain();
}

Cat::Cat(const Cat& cpyfrom) : Animal(cpyfrom)
{
	_brain = new Brain(*cpyfrom._brain);
	std::cout << "Copy constructor has been called\n";
}

Cat &Cat::operator=(const Cat& cpyfrom)
{
	if (this != &cpyfrom)
	{
		Animal::operator=(cpyfrom);
		delete _brain;
		_brain = new Brain(*cpyfrom._brain);
	}
	std::cout << "Cat assignment operator has been called\n";
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat has been destructed\n";
}

void Cat::makeSound() const
{
	std::cout << "MEOWWWRHG\n";
}

Brain *Cat::getBrain() const
{
	return (_brain);
}