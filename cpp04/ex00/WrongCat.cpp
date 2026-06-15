#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat default has been constructed\n";
}

WrongCat::WrongCat(std::string _type) : WrongAnimal(_type)
{
	_type = "WrongCat";
	std::cout << "WrongCat " << _type << " has been constructed\n";
}

WrongCat::WrongCat(const WrongCat& cpyfrom) : WrongAnimal(cpyfrom)
{
	std::cout << "Copy constructor has been called\n";
}

WrongCat &WrongCat::operator=(const WrongCat& cpyfrom)
{
	if (this != &cpyfrom)
		WrongAnimal::operator=(cpyfrom);
	std::cout << "WrongCat assignment operator has been called\n";
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat has been destructed\n";
}

void WrongCat::makeSound() const
{
	std::cout << "MEOWWWRHG\n";
}